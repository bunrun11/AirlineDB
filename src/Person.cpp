/*
 * Person.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: Job
 */

#include "Person.h"

Person::Person(){
	mfirstname = "";
	mlastname = "";
	maddress = "";
	mphonenumber = "";
}

Person::Person(std::string _firstname, std::string _lastname, std::string _address, std::string _phonenumber) {
	mfirstname = _firstname;
	mlastname = _lastname;
	maddress = _address;
	mphonenumber = _phonenumber;
}

Person::~Person() {

}

//returns first name
std::string Person::getFirstName(){
	return mfirstname;
}

//returns last name
std::string Person::getLastName(){
	return mlastname;
}

//returns address
std::string Person::getAddress(){
	return maddress;
}

//returns phonenumber
std::string Person::getPhoneumber(){
	return mphonenumber;
}

//sets firstname
void Person::setFirstName(std::string newFirstname){
	mfirstname = newFirstname;
}

//sets lastname
void Person::setLastName(std::string newLastname){
	mlastname = newLastname;
}

//sets address
void Person::setAddress(std::string newAddress){
	maddress = newAddress;
}

//sets phonenumber
void Person::setPhonenumber(std::string newPhonenumber){
	mphonenumber = newPhonenumber;
}

//prints all the person's data
void Person::print(){
	std::cout<<"First name: "<<mfirstname<<std::endl;
	std::cout<<"Last name: "<<mlastname<<std::endl;
	std::cout<<"Address: "<<maddress<<std::endl;
	std::cout<<"Phone: "<<mphonenumber<<std::endl;
}

std::ostream& operator<<(std::ostream& os, Person& p){
	os << p.mfirstname << " " << p.mlastname;
	if(p.maddress != ""){
		os << " ["<<p.maddress<<"]";
	}
	if(p.mphonenumber != ""){
		os << " ["<<p.mphonenumber<<"]";
	}
	return os;
}

bool operator== (Person& person1, Person& person2){
	return person1.mfirstname+person1.mlastname == person2.mfirstname+person2.mlastname;
}

bool operator< (Person& person1, Person& person2){
	return person1.mlastname.compare(person2.mlastname) > 0;
}

bool operator> (Person& person1, Person& person2){
	return !(person1 < person2) && !(person1 == person2);
}

