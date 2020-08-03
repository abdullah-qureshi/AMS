#include "AMS.h"

AMS::AMS() //Default constructor
{
	cout << "Enter airlines name: ";
	cin.ignore();
	getline(cin, airlineName);
	cout << "Enter airlines code: ";
	getline(cin, airlineCode);

}

AMS::AMS(string a, string b)
{
	airlineName = a;
	airlineCode = b;
}
void AMS::loadFlights(string fileName)
{
	ifstream file;
	file.open(fileName);
	while (file)
	{
		string origin, destination, fCode, time,price;

		getline(file, fCode, ',');
		getline(file, origin, ',');
		getline(file, destination, ',');
		getline(file, time, ',');
		getline(file, price, '\n');

		if (fCode == "") // Break the loop when empty line is encountered.
			break;
		addFlight(stoi(fCode), origin, destination, stoi(time), stof(price));

	}
}

void AMS::saveFlights(string fileName) // Function to save flights in a .csv file
{
	ofstream file;
	file.open(fileName, ofstream::trunc); // Open file in overwrite mode.

	for (auto &flight:flights) // Loop through flights to save all flights.
	{
		// Write the flight details in a .csv file.
		file << flight.get_flight_code() << ",";
		file << flight.get_departure() << ",";
		file << flight.get_arrival() << ",";
		file << flight.get_duration() << ",";
		file << flight.get_ticket_price() << "\n";
	}
}
void AMS::addFlight()
{
	Flight newFlight;
	newFlight.set_airline_code(airlineCode);
	//Check if flight with this code already exists?
	if (getFlight(newFlight.get_flight_code()) == flights.end())
	{
		flights.push_back(newFlight);
		cout << "Flight " << airlineCode << newFlight.get_flight_code() << " added successfully." << "\n\n";
	}
	else
		cout << "Flight " << airlineCode << newFlight.get_flight_code() << " already exists." << "\n\n";
	
}

void AMS::addFlight(int a, string b, string c, int t, float p)
{
	Flight newFlight (a, b, c,t, p);
	newFlight.set_airline_code(airlineCode);
	//If an existing flight with same flight code doesnt exist then add new flight.
	if (getFlight(newFlight.get_flight_code()) == flights.end())
	{
		flights.push_back(newFlight);
		cout << "Flight " << airlineCode << newFlight.get_flight_code() << " added successfully." << "\n\n";
	}
	else
		cout << "Flight " << airlineCode << newFlight.get_flight_code() << " already exists." << "\n\n";
}

itrFlight AMS::getFlight()
{
	displayFlights();
	cout << "Enter Flight code: ";
	int fCode;
	cin >> fCode;
	cin.clear();
	cin.ignore(10000, '\n');
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
		cin.clear();
		cin.ignore(10000, '\n');
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
	{ //Remove all bookings for deleted flight.
		for (auto passenger = users.begin(); passenger != users.end(); passenger++)
		{
			passenger->removeFlight(*toDelete); //Remove all bookings on deleted flights.
		}
		cout << "Flight " <<airlineCode<<toDelete->get_flight_code()  <<" deleted successfully."<<endl;
		flights.erase(toDelete);

	}
	else
		cout << "Invalid flight ID or Flight does not exist.\n";
		
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
		cout << "\nUser added succesfully." << endl;
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
void AMS::loadUsers(string fileName)
{
	ifstream file;
	file.open(fileName);
	while (file)
	{
		string fname, lname, num, cnic, mail;

		getline(file, fname, ',');
		getline(file, lname, ',');
		getline(file, num, ',');
		getline(file, cnic, ',');
		getline(file, mail, '\n');

		if (fname == "") // Break the loop when empty line is encountered.
			break;
		addUser(fname,lname,num,cnic,mail);

	}
}

void AMS::saveUsers(string fileName) // Function to save flights in a .csv file
{
	ofstream file;
	file.open(fileName, ofstream::trunc); // Open file in overwrite mode.

	for (auto& user : users) // Loop through flights to save all flights.
	{
		// Write the flight details in a .csv file.
		file << user.get_first_name() << ",";
		file << user.get_last_name() << ",";
		file << user.get_number() << ",";
		file << user.get_cnic() << ",";
		file << user.get_email() << "\n";
	}
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

bool AMS::checkUser(itrPassenger user)
{
	if (user == users.end())
		return false;

	else
		return true;
}


void AMS::deleteUser()
{
	cout << "Enter User ID: ";
	int id;
	cin >> id;
	cin.clear();
	cin.ignore(10000, '\n');
	itrPassenger toDelete = getUser(id);
	if (toDelete != users.end())
	{
		//Remove all bookings of deleted user.
		for (auto flight = flights.begin(); flight != flights.end(); flight++)
		{
			flight->removePassenger(*toDelete);
		}
		cout << "User "<< toDelete->get_full_name() << " deleted successfully." << endl;
		users.erase(toDelete);
	}
	else
		cout << "User does not exist.\n";

}

void AMS::editUser(itrPassenger user) // Function to change details of a contact.
	{
		cout << "\nUser ID: " << user->get_id() << endl;
		cout << "Name: " << user->get_full_name() << endl;
		cout << "CNIC: " << user->get_cnic() << endl;
		cout << "Phone: " << user->get_number() << endl;
		cout << "Email: " << user->get_email() << endl;
		cout << "Select details need to be changed.\n";
		cout << "1. First Name\n2. Last Name\n3. CNIC\n4. Phone\n5. Email"<< endl;
		int selection;
		cin >> selection;
		string edit; 
		switch (selection) // Change details according to selected option.
			{
			case 1:
				cout << "Enter new first name: ";
				cin >> edit;
				user->set_first_name(edit);
				break;
			case 2:
				cout << "Enter new last name: ";
				cin >> edit;
				user->set_last_name(edit);
				break;
			case 3:
				cout << "Enter new CNIC: ";
				cin >> edit;
				user->set_cnic(edit);
				break;
			case 4:
				cout << "Enter new Phone#:  ";
				cin >> edit;
				user->set_number(edit);
				break;
			case 5:
				cout << "Enter new email: ";
				cin >> edit;
				user->set_email(edit);
				break;
			default:
				cout << "Enter a valid option.";
				break;
			}
			cout << "User updated successfully." << endl;

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

void AMS::printTicket(itrFlight flight, itrPassenger user)
{
	system("cls");
	cout << "\t\t\t\t" <<airlineName <<endl;
	for (int i = 0; i <= 100; i++)
		cout << "*";
	cout << "\n\n";
	cout << left << "User ID: " << user->get_id() << endl;
	cout << left << setw(50)<< "Passenger: " + user->get_full_name();
	cout << left << setw(50)<<"CNIC#" +  user->get_cnic() << "\n";
	cout << left << setw(50) <<"Phone: " + user->get_number();
	cout <<left << setw(50)<<"Email: " + user->get_email() << "\n\n";
	cout << "FLIGHT INFO\n";
	cout << left << setw(10)<< "Flight: " +flight->get_airline_code() << left << setw(40) << flight->get_flight_code();
	cout<< left << setw(12) << "Duration: " << left << setw(5) << flight->get_duration() << left << setw(5) <<" min "<<"\n\n";
	cout << left << setw(50) << "Departure: " + flight->get_departure();
	cout<< left << setw(50) << "Arrival: " + flight->get_arrival() << "\n\n\n";
	cout << right << setw(10) << "Price: " << flight->get_ticket_price() << " PKR" << endl;
	for (int i = 0; i <= 100; i++)
		cout << "*";
}

void AMS::bookFlight(itrFlight flight, itrPassenger user)
{
	if (flight == flights.end())
		cout << "Invalid flight ID or Flight does not exist." << endl;
	else if (user->checkFlight(*flight)) //If user is already booked on the flight.
		cout << "User is already booked on this flight." << endl; 
	else if (flight->get_booked_seats() >= flight->get_total_seats())
	{
		cout << "Sorry the flight is fully booked. Please select another flight." << endl;
	}
	else
	{
		printTicket(flight, user); //Display ticket to user.
		cout << "\nPress 1 to confirm (0 to exit): ";
		int confirm = 0;
		cin >> confirm;

		if (confirm == 1)
		{
			flight->addPassenger(*user);
			user->addFlight(*flight);

			cout << "Flight " << flight->get_airline_code() << flight->get_flight_code() << " booked for " << user->get_full_name() << endl;
		}
	}
}

void AMS::cancelFlight(itrPassenger user)
{
	cout << "Select flight you want to cancel: " << endl;
	user->listBookedFlights();
	cout << "Enter flight ID for cancellation: ";
	int fID;
	cin >> fID;
	itrFlight toCancel = getFlight(fID);

	if (toCancel == flights.end())
		cout << "Invalid flight ID or Flight does not exist." << endl;
	else
	{
		//Remove flight from user's booked flights.
		user->removeFlight(*toCancel);
		//Remove passenger from flight
		toCancel->removePassenger(*user);
		toCancel->set_booked_seats(toCancel->get_booked_seats() - 1); //Remove book seat.
		cout << "Flight " << fID << " cancelled successfully." << endl;
	}
}