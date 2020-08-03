#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class AMS;
class Flight;
class Passenger; //Forward declaration to avoid any errors.
class Flight
{
	int flight_code, duration;
	float ticket_price;
	string departure, arrival;
	string airline_code = "PK";
	unsigned int total_seats = 100, booked_seats = 0;
	vector <Passenger> passengers; // Passengers Array to be added here.
public:
	//Default Constructor
	Flight();
	//Constructor
	Flight(int, string, string,int, float); // Code, Departure, Arrival, Duration, Ticket Price
	//Flight(string); // Airline code

	//Setter functions
	void set_flight_code(int);
	void set_airline_code(string);
	void set_duration(int);
	void set_departure(string);
	void set_arrival(string);
	void set_ticket_price(float);
	void set_total_seats(unsigned int);
	void set_booked_seats(unsigned int);

	//Get functions
	int get_flight_code() const;
	int get_duration() const;
	string get_departure() const;
	string get_arrival() const;
	string get_airline_code() const;
	float get_ticket_price() const;
	unsigned int get_total_seats() const;
	unsigned int get_booked_seats() const;

	//Add Passenger to Flight
	void addPassenger(Passenger);
	void removePassenger(Passenger);
	void listPassengers(); //List all passengers on current flight.
	void printDetails(string) const; // Print all details of flight in tabular form.

	
};

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

	//Setters
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

	//Book a flight.
	void addFlight(Flight);
	//Remove a booked flight
	void removeFlight(Flight);
	//Check if user is booked on a flight.
	bool checkFlight(Flight);//Return 1 if user is booked and 0 if user is not booked.
	//List Booked flights for a passenger.
	void listBookedFlights();
	void details();
};

