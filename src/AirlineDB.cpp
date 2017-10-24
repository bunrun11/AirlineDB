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
#include "FlightManager.h"

using namespace std;

int main() {

	FlightManager manager;
	manager.addFlight(*new Flight("100"));
	manager.addFlight(*new Flight("200"));
	manager.addFlight(*new Flight("300"));
	manager.addFlight(*new Flight("400"));

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
				manager.addPassenger();
				break;

			case 's' :
			case 'S' :
				manager.findPassenger();
				break;

			case 'd' :
			case 'D' :
				manager.deletePassanger();
				break;

			case 'l' :
			case 'L' :
				manager.printFlight();
				break;
		}
		cout<<endl;
	}
	return 0;
}


