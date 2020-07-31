#pragma once
#include "Flight.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Passenger
{
private:
	// Good programming practice to declare variables in private
	string first_name, last_name, full_name, number;
	string email, cnic;
	int ID;
	vector <Flight> bookedFlights;
	static int passengerID;
public:
	Passenger();
	Passenger(string, string, string, string, string); // FirstName,LastName,Phone Number, CNIC, Email.

	//Settersh
	void set_first_name(string a) { first_name = a; }
	void set_last_name(string a) { last_name = a; }
	void set_full_name() { full_name = first_name + " " + last_name; }
	void set_number(string a) { number = a; }
	void set_email(string a) { email = a; }
	void set_cnic(string a) { cnic = a; }

	//Getters
	string get_first_name() { return first_name; }
	string get_last_name() { return last_name; }
	string get_full_name() { return full_name; }
	string get_number() { return number; }
	string get_email() { return email; }
	string get_cnic() { return cnic; }
	int get_id() { return ID; }

	//void deletion();
	//void add_passenger();
	void details();
	//int search_passenger_byname(std::string);
	//int search_passenger_bynumber(std::string);
	//int check();
	//int verify();
	//void friend editor(passenger& obj);
};