#pragma once
#include "Flight-Passenger.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
typedef vector<Passenger>::iterator itrPassenger;
typedef vector<Flight>::iterator itrFlight;

class AMS
{

private:
	vector <Flight> flights;
	vector <Passenger> users;

public:
	string airlineName;
	string airlineCode;

	AMS(); //Default constructor.
	AMS(string, string);//Initialize object with airline name, code.

	void loadFlights(string); //Load flights from a .csv file.
	void saveFlights(string); //Save flights into a .csv file.

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
	
	void loadUsers(string); //load users from a .csv file.
	void saveUsers(string); //Save flights into a .csv file.

	void addUser(); // Add new user.
	void addUser(string, string, string, string , string); // FirstName,LastName, CNIC, Phone, Email
	void listUsers(); //Display list of all registered users.
	void deleteUser(); //Delete a user.
	void editUser(itrPassenger);
	itrPassenger getUser(string); //Get user by CNIC.
	itrPassenger getUser(int); // Get user by ID.
	bool checkUser(itrPassenger); // Check if a user exists.

	void bookFlight(itrFlight, itrPassenger);
	void cancelFlight(itrPassenger);
	void printTicket(itrFlight, itrPassenger); //Print a ticket for given flight and passenger.
	
};

