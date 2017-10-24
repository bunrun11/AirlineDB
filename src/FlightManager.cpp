/*
 * FlightManager.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: Job
 */

#include "FlightManager.h"

FlightManager::FlightManager() {

}

FlightManager::~FlightManager() {

}

//adds flight to the manager
void FlightManager::addFlight(Flight& flight){
	if(mflights[flight.getFlightNumber()] == 0){
		mflights.insert(flight);
	}
}

//adds a passenger to a flight
void FlightManager::addPassenger(){
	std::string flightNumber = getValidFlightNumber();
	std::string first = getStringInput("Enter first name: ");
	std::string last = getStringInput("Enter last name: ");
	std::string address, phone;
	std::cout<<"Enter address: ";
	address = getInput();
	std::cout<<"Enter phone: ";
	phone = getInput();
	mflights[flightNumber]->addPassenger(*(new Person(first, last, address, phone)));
}

//finds whether a passenger is present on a flight
void FlightManager::findPassenger(){
	std::string first = getStringInput("Enter first name: ");
	std::string last = getStringInput("Enter last name: ");
	Person p(first, last, "", "");

	bool isFound = false;
	for(typename LinkedList<Flight>::Iterator it = mflights.getIterator(); it.hasNext(); it.next()){
		if(it.getValue().searchFlight(p)){
			std::cout<<"Flight number: "<<it.getValue().getFlightNumber()<<std::endl;
			it.getValue().findPassenger(p).print();
			isFound = true;
		}
	}
	if(!isFound){
		std::cout<<"Passenger not found."<<std::endl;
	}
}

//deletes a passenger from a flight
void FlightManager::deletePassanger(){
	std::string flightNumber = getValidFlightNumber();
	std::string first = getStringInput("Enter first name: ");
	std::string last = getStringInput("Enter last name: ");
	Person p(first, last, "", "");
	if(mflights[flightNumber]->searchFlight(p)){
		mflights[flightNumber]->removePassenger(p);
		std::cout<<"The passenger was deleted."<<std::endl;
	}
	else{
		std::cout<<"Passenger not found!"<<std::endl;
	}
}

//prints out all flights passengers
void FlightManager::printFlight(){
	std::string flightNumber = getValidFlightNumber();
	std::cout<<(*mflights[flightNumber]);
}

std::string FlightManager::getInput(){
	char s[1000];

	std::cin.getline(s, 1000);
	for(int i = 0; i < 1000; i++){
		if(s[i] == '\n' || s[i] == '\r'){
			s[i] = 0;
		}
		if(s[i] < 0){
			break;
		}
	}
	return s;
}

std::string FlightManager::getStringInput(std::string message){
	char s[1000];

	bool isValid = 1;
	do{
		std::cout<<message;
		std::cin.getline(s, 1000);

		for(int i = 0; i < 1000; i++){
			if(s[i] == '\n' || s[i] == '\r'){
				s[i] = 0;
			}
			if(s[i] < 0){
				break;
			}
		}

		isValid = validateString(s);
		if(!isValid){
			std::cout<<"That is not a valid name!"<<std::endl;
		}
	}while(!isValid);

	return s;
}

std::string FlightManager::getIntInput(std::string message){
	char s[1000];

	bool isValid = 1;
	do{
		std::cout<<message;
		std::cin.getline(s, 1000);

		for(int i = 0; i < 1000; i++){
			if(s[i] == '\n' || s[i] == '\r'){
				s[i] = 0;
			}
			if(s[i] < 0){
				break;
			}
		}

		isValid = validateNumber(s);
		if(!isValid){
			std::cout<<"That is not a valid number!"<<std::endl;
		}
	}while(!isValid);

	return s;
}

std::string FlightManager::getValidFlightNumber(){
	bool isValid = false;
	std::string num;
	while(isValid == false){
		num = getIntInput("Enter flight number: ");

		if(mflights[num]){
			isValid = true;
		}
		else{
			std::cout<<"That is not a valid flight number!"<<std::endl;
		}
	}

	return num;
}

bool FlightManager::validateString(std::string s){
	for(std::string::iterator it = s.begin(); it != s.end(); it++){
		if(!isalpha(*it) && !isspace(*it)){
			return 0;
		}
	}

	return 1;
}

bool FlightManager::validateNumber(std::string number){
	for(std::string::iterator it = number.begin(); it != number.end(); it++){
		if(!isdigit(*it) && ((*it == ' ') || !isspace(*it))){
			return 0;
		}
	}

	return 1;
}

