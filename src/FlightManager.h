/*
 * FlightManager.h
 *
 *  Created on: Oct 23, 2017
 *      Author: Job
 */

#ifndef FLIGHTMANAGER_H_
#define FLIGHTMANAGER_H_

#include "flight.h"

class FlightManager {
	LinkedList<Flight> mflights;

public:
	FlightManager();
	~FlightManager();

	void addFlight(Flight&);

	void addPassenger();
	void findPassenger();
	void deletePassanger();
	void printFlight();

private:
	std::string getInput();
	std::string getStringInput(std::string message);
	std::string getIntInput(std::string message);
	std::string getValidFlightNumber();

	bool validateString(std::string);
	bool validateNumber(std::string);
};

#endif /* FLIGHTMANAGER_H_ */
