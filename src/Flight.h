/*
 * Flight.h
 *
 *  Created on: Oct 23, 2017
 *      Author: Job
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include "OrderedLinkedList.h"
#include "Person.h"

class Flight{
	OrderedLinkedList<Person> passengers;
	std::string mflightNumber;

public:
	Flight(std::string);
	~Flight();

	std::string getFlightNumber();
	void setFlightNumber(std::string);

	void addPassenger(Person&);
	void removePassenger(Person&);
	bool searchFlight(Person&);
	Person findPassenger(Person&);

	friend bool operator== (Flight&, Flight&);
	friend bool operator== (std::string&, Flight&);
	friend std::ostream& operator<< (std::ostream&, Flight&);
};

#endif /* FLIGHT_H_ */
