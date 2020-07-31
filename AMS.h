#pragma once
#include "Flight-Passenger.h"
#include <iostream>
#include <vector>

using namespace std;
typedef vector<Passenger>::iterator itrPassenger;
typedef vector<Flight>::iterator itrFlight;

class AMS
{

private:
	string airlineName;
	string airlineCode = "PK";
	vector <Flight> flights;
	vector <Passenger> users;

public:
	void addFlight(); //Add a new flight.
	void addFlight(int, string, string, int, float); // Parameterized function for adding flight. FLIGHTCODE, ORIGIN, DESTINATION, DURATION, TICKET PRICE.
	void deleteFlight(); //Delete a flight.
	itrFlight getFlight(); //Get flight.
	itrFlight getFlight(int); //Get flight by ID.
	itrFlight getFlight(string origin, string destination); //Get flight by departure and arrival city.
	itrFlight getFlightByOrigin(string);
	itrFlight getFlightByDestination(string);
	void displayFlights(vector <Flight>); // Display flights details of the flights in input vector.
	void displayFlights(); // Display all flights.
	
	void addUser(); // Add new user.
	void addUser(string, string, string, string , string); // FirstName,LastName,Phone Number, CNIC, Email
	void listUsers(); //Display list of all registered users.
	void deleteUser(); //Delete a user.
	itrPassenger getUser(string); //Get user by CNIC.
	itrPassenger getUser(int); // Get user by ID.

	void bookFlight(itrFlight, itrPassenger);
	
};

