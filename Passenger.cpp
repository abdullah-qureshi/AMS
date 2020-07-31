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
/*void Passenger::deletion()
{
	passengerid = 0000;
	first_name = " ";
	last_name = " ";
	number = "000000";
	gender = "nil";
	address = "lalaland";
	email = "nothing";
	cnic = "3740600000000";
}*/

/*void Passenger::add_passenger()
{
	// This is for adding contact
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
	cout << "Enter Address: ";
	cin.ignore(); // cin.ignore() is necessary before getline otherwise getline does not work
	getline(cin, address);
	cout << "Enter the Gender: ";
	cin >> gender;
	srand(time(NULL));
	passengerID = rand() % 10000;
	cout << "\n\nPassenger has been successfully added" << endl;
	Sleep(500); // Sleep introduces gap in the program
	return;
}*/

void Passenger::details()
{
	cout << left << setw(5) << ID;
	cout << left << setw(25) << full_name;
	cout << left << setw(18) << cnic;
	cout << left << setw(15) << number;
	cout << left << setw(25) << email <<endl;
}

/*int passenger::search_passenger_bynumber(string n) // similar stuff for finding by number to the above function except no transform
{
	if (number == n)
	{
		cout << "Found it!!!\n\n";
		cout << "Name: " << full_name << endl;
		cout << "ID: " << passengerID << endl;
		cout << "Number: " << number << endl;
		cout << "Email: " << email << endl;
		cout << "Address: " << address << endl;
		cout << "Gender: " << gender << endl;
		cout << "CNIC: " << cnic << endl;
		char cont;
		cout << "Here's your contact, press any key to continue: ";
		cin >> cont;
		return 1;
	}
	else
		return 0;
}*/

/*int passenger::search_passenger_byname(string n)
{
	string test = first_name; // We will store value of first_name in another string
	transform(test.begin(), test.end(), test.begin(), ::toupper); // this function capitalizes the test string
	if (test == n) // if the given string matches the test string then the contact has been found and it exists
	{
		// if contact has been successfully found it will display the details
		cout << "\nFound it!!!\n\n";
		cout << "Name: " << full_name << endl;
		cout << "ID: " << passengerID << endl;
		cout << "Number: " << number << endl;
		cout << "Email: " << email << endl;
		cout << "Address: " << address << endl;
		cout << "Gender: " << gender << endl;
		cout << "CNIC: " << cnic << endl;
		// Asking for user approval to resume
		char cont;
		cout << "\nHere's your contact, press any key to continue: ";
		cin >> cont;
		return 1;
	}
	else
	{
		return 0;
	}
}*/

/*int passenger::verify()
{
	// Verify is similar to check() except it does the opposite
	// Verify() returns 1 if the object does not have empty contact to call the details() function for printing list
	if (passenger::full_name == " " || passenger::number == "000000")
		return 0;
	else
		return 1;
}*/
/*
int passenger::check()
{
	// Check was used in the add_contact segment, if the object had an empty contact then returning 1 would call add_contact()
	if (passenger::full_name == " " || passenger::number == "000000")
		return 1;
	else
		return 0;
}*/
/*void editor(passenger& obj) // Editor was a friend function to update a contact
{
	char select, leave; // Two char variables will be used
	while (1) // Infinite loop
	{
		// Asking the user which contact they want to modify
		cout << "\n\nWhich feature do you want to edit?\n1. Name\n2. Number\n3. Email\n4. Address\n5. Gender\n6. Relation ";
		cout << "\nEnter the corresponding number to edit the detail: ";
		cin >> select;
		switch (select) // A switch has been applied
		{
		case '1': // 1 will ask user for name change
			cout << "Enter the first name: ";
			cin >> obj.first_name;
			cout << "Enter the last name: ";
			cin >> obj.last_name;
			obj.full_name = obj.first_name + " " + obj.last_name;
			cout << "Name changed successfully" << endl;
			break;
		case '2': // 2 will ask for number change
			cout << "Enter the number: ";
			cin >> obj.number;
			cout << "Number has been changed successfully" << endl;
			break;
		case '3': // 3 will ask for email change
			cout << "Enter the email: ";
			cin >> obj.email;
			cout << "Email has been changed succesfully" << endl;
			break;
		case '4': // 4 will ask for address change
			cout << "Enter the address: ";
			cin.ignore();
			getline(cin, obj.address);
			cout << "Address has been changed succesfully" << endl;
			break;
		case '5': // 5 will ask for gender change
			cout << "Enter the gender: ";
			cin >> obj.gender;
			cout << "Gender has been changed successfully" << endl;
			break;
		case '6': // 6 will ask for relation change
			cout << "Enter the CNIC: ";
			cin >> obj.cnic;
			cout << "Relation has been changed successfully" << endl;
			break;
		default: // Anything else entered is considered incorrect
			cout << "Incorrect option\n";
		}
		// Now it will ask to break the infinite loop or is there something else to edit
		cout << "\nAnything else you want to edit, if no then press q to exit this feature, else press any other key\n";
		cout << "Enter here: ";
		cin >> leave;
		Sleep(500);
		if (leave == 'q' || leave == 'Q')
			break;
		else
			cout << "Ok here we go again" << endl;
	}
}*/