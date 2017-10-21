//============================================================================
// Name        : AirlineDB.cpp
// Author      : Job Betcher
// Date        : 10/20/2017
// Description : Assignment #2 Four OrdedLinkedLists to store passenger data.
//============================================================================

#include <map>
#include <iostream>
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Person.h"

using namespace std;

void add();
void search();
void deletePassanger();
void printList();

string getInput();
string getIntInput(string);
string getStringInput(string);
string getValidFlightNumber();


map<string, OrderedLinkedList<Person>> flights;

int main() {

	flights["100"] = OrderedLinkedList<Person>();
	flights["200"] = OrderedLinkedList<Person>();
	flights["300"] = OrderedLinkedList<Person>();
	flights["400"] = OrderedLinkedList<Person>();

	cout<<"***DELTA AIRLINES***"<<endl;
	cout<<"Please choose an operation:"<<endl;

	char user;
	while(user != 'Q' && user != 'q'){
		cout<<"A(Add)|S(Search)|D(Delete)|L(List)|Q(Quit): ";
		cin>>user;
		cin.ignore(1000, '\n');
		//cin.ignore('\r');

		switch(user){
			case 'a' :
			case 'A' :
				add();
				break;

			case 's' :
			case 'S' :
				search();
				break;

			case 'd' :
			case 'D' :
				deletePassanger();
				break;

			case 'l' :
			case 'L' :
				printList();
				break;
		}
		cout<<endl;
	}
	return 0;
}

void add(){
	string flightNumber = getValidFlightNumber();
	string first = getStringInput("Enter first name: ");
	string last = getStringInput("Enter last name: ");
	string address, phone;
	cout<<"Enter address: ";
	address = getInput();
	cout<<"Enter phone: ";
	phone = getInput();
	flights[flightNumber].insert(*(new Person(first, last, address, phone)));
}

void search(){
	string first = getStringInput("Enter first name: ");
	string last = getStringInput("Enter last name: ");
	Person p(first, last, "", "");

	bool isFound = false;
	for(map<string, OrderedLinkedList<Person>>::iterator it = flights.begin(); it != flights.end(); it++){
		if(it->second.find(p)){
			cout<<"Flight number: "<<it->first<<endl;
			it->second.search(p).print();
			isFound = true;
		}
	}
	/*
	for(pair<string, OrderedLinkedList<Person>> flight& : flights){
		if(flight.second.find(p)){
			cout<<"Flight number: "<<flight.first<<endl;
			flight.second.search(p).print();
			isFound = true;
		}
	}
	*/
	if(!isFound){
		cout<<"Passenger not found."<<endl;
	}
}

void deletePassanger(){
	string flightNumber = getValidFlightNumber();
	string first = getStringInput("Enter first name: ");
	string last = getStringInput("Enter last name: ");
	Person p(first, last, "", "");
	if(flights[flightNumber].find(p)){
		flights[flightNumber].deleteData(p);
		cout<<"The passenger was deleted."<<endl;
	}
	else{
		cout<<"Passenger not found!"<<endl;
	}
}

void printList(){
	string flightNumber = getValidFlightNumber();
	flights[flightNumber].print();
}


string getInput(){
	char s[1000];

	cin.getline(s, 1000);
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


bool validateString(string s){
	for(string::iterator it = s.begin(); it != s.end(); it++){
		if(!isalpha(*it) && !isspace(*it)){
			return 0;
		}
	}

	return 1;
}

string getStringInput(string message){
	char s[1000];

	bool isValid = 1;
	do{
		cout<<message;
		cin.getline(s, 1000);

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
			cout<<"That is not a valid name!"<<endl;
		}
	}while(!isValid);

	return s;
}


bool validateNumber(string number){
	for(string::iterator it = number.begin(); it != number.end(); it++){
		if(!isdigit(*it) && ((*it == ' ') || !isspace(*it))){
			return 0;
		}
	}

	return 1;
}

string getIntInput(string message){
	char s[1000];

	bool isValid = 1;
	do{
		cout<<message;
		cin.getline(s, 1000);

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
			cout<<"That is not a valid number!"<<endl;
		}
	}while(!isValid);

	return s;
}

string getValidFlightNumber(){
	bool isValid = false;
	string num;
	while(isValid == false){
		num = getIntInput("Enter flight number: ");

		if(flights.count(num)){
			isValid = true;
		}
		else{
			cout<<"That is not a valid flight number!"<<endl;
		}
	}

	return num;
}




