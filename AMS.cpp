#include "AMS.h"

void AMS::addFlight()
{
	Flight newFlight;
	//Check if flight with this code already exists?
	if (getFlight(newFlight.get_flight_code()) == flights.end())
	{
		flights.push_back(newFlight);
		cout << "Flight " << airlineCode << newFlight.get_flight_code() << " added successfully." << endl;
	}
	else
		cout << "Flight " << airlineCode << newFlight.get_flight_code() << " already exists." << endl;
	
}

void AMS::addFlight(int a, string b, string c, int t, float p)
{
	Flight newFlight (a, b, c,t, p);
	//If an existing flight with same flight code doesnt exist then add new flight.
	if (getFlight(newFlight.get_flight_code()) == flights.end())
	{
		flights.push_back(newFlight);
		cout << "Flight " << airlineCode << newFlight.get_flight_code() << " added successfully." << endl;
	}
	else
		cout << "Flight " << airlineCode << newFlight.get_flight_code() << " already exists." << endl;
}

itrFlight AMS::getFlight()
{
	displayFlights();
	cout << "Enter Flight code: ";
	int fCode;
	cin >> fCode;
	return getFlight(fCode);
}

itrFlight AMS::getFlight(int fCode)
{
	for (itrFlight flight = flights.begin(); flight != flights.end(); flight++)
	{
		if (fCode == flight->get_flight_code())
		{
			return flight;
		}
	}
	return flights.end(); // Return null when nothing is found.
}

itrFlight AMS::getFlight(string origin, string destination)
{
	vector <Flight> matchedResults;
	for (itrFlight flight = flights.begin(); flight != flights.end(); flight++)
	{
		if (origin == flight->get_departure() && destination == flight->get_arrival())
		{
			matchedResults.push_back(*flight);
		}
	}
	cout << matchedResults.size()<< " flights found." << endl;
	displayFlights(matchedResults);
	if (!matchedResults.empty()) {
		cout << "Enter Flight code (3-digits): ";
		int fCode;
		cin >> fCode;
		return getFlight(fCode);
	}
	else
		return flights.end();
}

itrFlight AMS::getFlightByOrigin(string origin)
{
	vector <Flight> matchedResults;
	for (itrFlight flight = flights.begin(); flight != flights.end(); flight++)
	{
		if (origin == flight->get_departure())
		{
			matchedResults.push_back(*flight);
		}
	}
	cout << matchedResults.size() << " flights found." << endl;
	displayFlights(matchedResults);
	if (!matchedResults.empty()) {
		cout << "Enter Flight code (3-digits): ";
		int fCode;
		cin >> fCode;
		return getFlight(fCode);
	}
	else
		return flights.end();
}
itrFlight AMS::getFlightByDestination(string destination)
{
	vector <Flight> matchedResults;
	for (itrFlight flight = flights.begin(); flight != flights.end(); flight++)
	{
		if (destination == flight->get_arrival())
		{
			matchedResults.push_back(*flight);
		}
	}
	cout << matchedResults.size() << " flights found." << endl;
	displayFlights(matchedResults);
	if (!matchedResults.empty()) {
		cout << "Enter Flight code (3-digits): ";
		int fCode;
		cin >> fCode;
		return getFlight(fCode);
	}
	else
		return flights.end();
}

void AMS::deleteFlight()
{
	itrFlight toDelete = getFlight();
	if (toDelete != flights.end())
	{
		cout << "Flight " <<airlineCode<<toDelete->get_flight_code()  <<" deleted successfully."<<endl;
		flights.erase(toDelete);
	}
	else
		cout << "Flight does not exist.\n";
		
}

void AMS::displayFlights()
{
	cout << left << setw(8) << "Code";
	cout << left << setw(20) << "Departure";
	cout << left << setw(20) << "Arrival";
	cout << left << setw(6) << "Duration(min)\n\n";
	for (auto& flight : flights)
		flight.printDetails(airlineCode);
}

void AMS::displayFlights(vector <Flight> flights)
{
	cout << left << setw(8) << "Code";
	cout << left << setw(20) << "Departure";
	cout << left << setw(20) << "Arrival";
	cout << left << setw(6) << "Duration\n\n";
	for (auto& flight : flights)
		flight.printDetails(airlineCode);
}

void AMS::addUser()
{
	Passenger newUser;
	if (getUser(newUser.get_cnic()) == users.end())
	{
		users.push_back(newUser);
		cout << "User added succesfully." << endl;
		cout << "User ID: " << newUser.get_id() << endl;
		cout << "Name: " << newUser.get_full_name() << endl;
		cout << "CNIC: " << newUser.get_cnic() << "\n\n";
	}
	else
		cout << "User with this CNIC already exists." << endl;
}

void AMS::addUser(string a, string b, string cnic_id, string num, string mail)
{
	Passenger newUser(a,b,cnic_id,num,mail); // FirstName,LastName,Phone Number, CNIC, Email
	if (getUser(newUser.get_cnic()) == users.end())
	{
		users.push_back(newUser);
		cout << "User added succesfully." << endl;
		cout << "User ID: " << newUser.get_id() << endl;
		cout << "Name: " << newUser.get_full_name() << endl;
		cout << "CNIC: " << newUser.get_cnic() << "\n\n";
	}
	else
		cout << "User with this CNIC already exists." << endl;
}

itrPassenger AMS::getUser(string cnic_id)
{
	for (itrPassenger user = users.begin(); user != users.end(); user++)
	{
		if (cnic_id == user->get_cnic())
		{
			return user;
		}
	}
	return users.end(); // Return null when nothing is found.
}

itrPassenger AMS::getUser(int userID)
{
	for (itrPassenger user = users.begin(); user != users.end(); user++)
	{
		if (userID == user->get_id())
		{
			return user;
		}
	}
	return users.end(); // Return null when nothing is found.
}


void AMS::deleteUser()
{
	cout << "Enter User ID: ";
	int id;
	cin >> id;
	itrPassenger toDelete = getUser(id);
	if (toDelete != users.end())
	{
		cout << "User "<< toDelete->get_full_name() << " deleted successfully." << endl;
		users.erase(toDelete);
	}
	else
		cout << "User does not exist.\n";

}

void AMS::listUsers()
{
	cout << left << setw(5) << "ID";
	cout << left << setw(25) << "Name:";
	cout << left << setw(18) << "CNIC #";
	cout << left << setw(15) << "Phone No.";
	cout << left << setw(25) << "Email" <<endl;

	for (auto& user : users)
	{
		user.details();
	}
}

void AMS::bookFlight(itrFlight flight, itrPassenger user)
{
	if (flight == flights.end())
		cout << "Please select a valid flight";
	else if (flight->get_booked_seats() < flight->get_total_seats())
	{
		cout << "\t\t\t\t Pakistan Air Lines" <<endl;
		cout << "#################################################################################################\n\n";
		cout << "Passenger: " << user->get_full_name() << "\t\tCNIC#" << user->get_cnic() <<"\n";
		cout << "Phone: " << user->get_number() << "\t\t\tEmail: " << user->get_email() << "\n\n";
		cout << "FLIGHT INFO\n";
		cout << "Flight: " << flight->get_airline_code()<<flight->get_flight_code()<< "\t\tDuration: " << flight->get_duration() << "\n\n";
		cout << "Departure: " << flight->get_departure() << "\tArrival: " << flight->get_arrival() << "\n\n\n";
		cout << "\t\t\t\t\t\tPrice: " << flight->get_ticket_price ()<< " PKR" << endl;
		cout << "#################################################################################################\n\n";

		cout << "Press 1 to confirm (any other key to cancel): ";
		int confirm = 0;
		cin >> confirm;

		if (confirm == 1)
		{
			flight->addPassenger(*user);
			user->addFlight(*flight);

			cout << "Flight " << flight->get_airline_code() << flight->get_flight_code() << " booked for " << user->get_full_name() <<endl;
		}
		
	}
	else
	{
		cout << "Sorry the flight is fully booked. Please select another flight." << endl;
	}
}
