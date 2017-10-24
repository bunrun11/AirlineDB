/*
 * Flight.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: Job
 */

#include "Flight.h"

Flight::Flight(std::string flightNumber){
	mflightNumber = flightNumber;
}

Flight::~Flight() {

}

//returns flight number;
std::string Flight::getFlightNumber(){
	return mflightNumber;
}

//sets flight number
void Flight::setFlightNumber(std::string newFlightNumber){
	mflightNumber = newFlightNumber;
}

//adds a passenger to the flight
void Flight::addPassenger(Person& person){
	passengers.insert(person);
}

//removes a passenger from the flight
void Flight::removePassenger(Person& person){
	passengers.deleteData(person);
}

//searches the flight to see whether the passenger is present
bool Flight::searchFlight(Person& person){
	return passengers.search(person);
}

//returns the passenger specified
Person Flight::findPassenger(Person& person){
	return passengers.find(person);
}

bool operator== (Flight& flight1, Flight& flight2){
	return flight1.getFlightNumber() == flight2.getFlightNumber();
}

bool operator== (std::string& s, Flight& flight){
	return s == flight.getFlightNumber();
}

std::ostream& operator<< (std::ostream& os, Flight& flight){
	os << flight.passengers;
	return os;
}

