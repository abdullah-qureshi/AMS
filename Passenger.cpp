#include "Flight-Passenger.h"
int Passenger::passengerID = 1000;
Passenger::Passenger()
{
	cout << "Enter the first name: ";
	cin >> first_name;
	cout << "Enter the last name: ";
	cin >> last_name;
	full_name = first_name + " " + last_name;
	cout << "Enter the phone number: ";
	cin >> number;
	cout << "Enter your CNIC No (without dashes) : ";
	cin >> cnic;
	cout << "Enter the Email: ";
	cin >> email;
	passengerID++;
	ID = passengerID;
}
Passenger::Passenger(string a, string b, string cnic_id, string num,  string mail)
{
	first_name = a;
	last_name = b;
	full_name = first_name + " " + last_name;
	cnic = cnic_id;
	number = num;
	email = mail;
	passengerID++;
	ID = passengerID;
}

void Passenger::addFlight(Flight newFlight)
{
	bookedFlights.push_back(newFlight);
}

void Passenger::removeFlight(Flight delFlight)
{
	for (auto flight = bookedFlights.begin(); flight != bookedFlights.end(); flight++)
	{
		if (flight->get_flight_code() == delFlight.get_flight_code())
		{
			bookedFlights.erase(flight);
			break;
		}
	}
}

bool Passenger::checkFlight(Flight checkFlight)
{
	for (auto& flight : bookedFlights)
	{
		if (flight.get_flight_code() == checkFlight.get_flight_code())
			return true;
	}
	return false;
}
void Passenger::listBookedFlights()
{
	details();
	cout << endl;
	cout << left << setw(8) << "Code";
	cout << left << setw(20) << "Departure";
	cout << left << setw(20) << "Arrival";
	cout << left << setw(6) << "Duration\n\n";
	for (auto& flight :bookedFlights )
		flight.printDetails(flight.get_airline_code());
}
void Passenger::details()
{
	cout << left << setw(5) << ID;
	cout << left << setw(25) << full_name;
	cout << left << setw(18) << cnic;
	cout << left << setw(15) << number;
	cout << left << setw(25) << email <<endl;
}
