/*
 * Person.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Job
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

class Person {
	std::string mfirstname;
	std::string mlastname;
	std::string maddress;
	std::string mphonenumber;

public:
	Person();
	Person(std::string, std::string, std::string, std::string);
	~Person();

	std::string getFirstName();
	std::string getLastName();
	std::string getAddress();
	std::string getPhoneumber();

	void setFirstName(std::string);
	void setLastName(std::string);
	void setAddress(std::string);
	void setPhonenumber(std::string);

	void print();

	friend bool operator== (Person&, Person&);
	friend bool operator< (Person&, Person&);
	friend bool operator> (Person&, Person&);

	friend std::ostream& operator<<(std::ostream&, Person&);
};

#endif /* PERSON_H_ */
