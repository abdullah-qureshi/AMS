#include "Flight-Passenger.h"

Flight::Flight()
{
	cout << "Enter flight code: ";
	cin >> flight_code;

	cin.ignore(); 
	cout << "Enter Departure city: ";
	getline(cin, departure);

	cout << "Enter Arrival city: ";
	getline (cin, arrival);

	cout << "Enter flight duration (min): ";
	cin >> duration;

	cout << "Enter ticket price (PKR) : ";
	cin >> ticket_price;
}

Flight::Flight(int a, string b, string c, int t, float p)
{
	flight_code = a;
	departure = b;
	arrival = c;
	duration = t;
	ticket_price = p;
}

void Flight::set_flight_code(int a){flight_code = a;}
void Flight::set_departure(string b){departure = b;}
void Flight::set_arrival(string c){arrival = c;}
void Flight::set_duration(int t){duration = t;}
void Flight::set_ticket_price(float p){ticket_price = p;}
void Flight::set_booked_seats(unsigned int s) { booked_seats = s; }
void Flight::set_total_seats(unsigned int s) { total_seats = s; }

int Flight::get_flight_code() const{return flight_code;}
string Flight::get_departure() const{return departure;}
string Flight::get_arrival() const{return arrival;}
string Flight::get_airline_code() const { return airline_code; }
int Flight::get_duration() const{return duration;}
float Flight::get_ticket_price() const{return ticket_price;}
unsigned int Flight::get_total_seats() const { return total_seats; }
unsigned int Flight::get_booked_seats() const { return booked_seats; }

void Flight::printDetails(string airlineCode) const
{
	cout << left << setw(2) << airlineCode;
	cout << left << setw(6) << flight_code;
	cout << left << setw(20) << departure;
	cout << left << setw(20) << arrival;
	cout << left << setw(6) << duration << endl;
}

void Flight::addPassenger(Passenger newPassenger)
{
	passengers.push_back(newPassenger);
	booked_seats++;
}
void Flight::listPassengers()
{
	cout << left << setw(5) << "ID";
	cout << left << setw(25) << "Name:";
	cout << left << setw(18) << "CNIC #";
	cout << left << setw(15) << "Phone No.";
	cout << left << setw(25) << "Email" << endl;
	for (auto& passenger : passengers)
	{
		passenger.details();
	}
}