#include "AMS.h"
#include <iostream>
#include <Windows.h>
using namespace std;


							////////////////////////////////////////////////////////////////////////////////////////
													const string USER_NAME = "admin";
													const string PASSWORD = "1234569";
						   ////////////////////////////////////////////////////////////////////////////////////////


void user_menu(AMS& airline, itrPassenger loggedIn);
void admin_menu(AMS& airline);
int main()
{
	AMS airline ("AMS AIRLINES", "PK"); // Create an object of class AMS. Airline name = AMS AIRLINES.

	//Intro animation.
	cout << "....Booting" << endl;
	Sleep(2000);
	cout << "\n\nLoading flight data" << endl;
	airline.loadFlights("Flights.csv");
	Sleep(500);
	cout << "\n\nLoading user data" << endl;
	airline.loadUsers("Users.csv");
	Sleep(500);
	

	while (1)
	{
		system("cls");
		for (int i = 0; i <= 100; i++)
			cout << "*";
		cout << "\n\n\t\t\t\tWelcome to " << airline.airlineName << "\n\n";
		for (int i = 0; i <= 100; i++)
			cout << "*";
		Sleep(300);
		cout << "\nChoose your option \n\n1) Open User portal\n2) Admin Panel\n3) Register new account" << "\n(Q to exit)" << "\n\nEnter: ";
		char type;
		cin >> type;
		if (type == '1')
		{
			system("cls");
			cout << "\n\t\t\t1. Log in with CNIC";
			cout << "\n\n\t\t\t2. Log in with User ID";
			char option;
			cout << "\n\n>> ";
			cin >> option;
			itrPassenger loggedIn;
			if (option == '1')
			{
				string cnic;
				cout << " Enter your CNIC: ";
				cin >> cnic;
				loggedIn = airline.getUser(cnic);
			}
			else if (option == '2')
			{
				int id;
				cout << "Enter your User ID: ";
				cin >> id;
				loggedIn = airline.getUser(id);
			}
			else
			{
				cout << "Please enter a valid option." << endl;
				system("pause");
			}


			if (airline.checkUser(loggedIn))// Check if user login is valid.
			{
				user_menu(airline, loggedIn);
			}	
		}
		else if (type == '2')
		{
			system("cls");
			admin_menu(airline);
		}
		else if (type == '3')
		{
			system("cls");
			airline.addUser();
			system("pause");
		}
		else if (type == 'q' || type == 'Q')
		{
			cout << "Thank you for using our services" << endl;
			break;
		}

		else
			cout << "Illegal option" << endl;
	}

	return 0;
}

void user_menu(AMS& airline, itrPassenger loggedIn)
{
	
	Sleep(1000);
	while (1)
	{
		system("cls");
		for (int i = 0; i <= 100; i++)
			cout << "*";
		cout << "\n\n\t\t\t\tUser Portal" << "\n\n";
		for (int i = 0; i <= 100; i++)
			cout << "*";
					
		cout << "\nWelcome, " << loggedIn->get_full_name() << "!\n\n ";
		cout << "What do you want to do?" << endl;
		cout << "1. Show all flights\n2. Book Flight\n3. Check Current Booked Flights\n4. Edit User info\n5. Cancel flight\n6. Exit";
		
		cout << "\n\nEnter the corresponding number for the option: ";
		char option;
		cin >> option;
		Sleep(1000);
		switch (option)
		{
		case '1':
		{
			system("cls");
			airline.displayFlights();
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			cout << "Search Flight by\n\n1) Origin\n2) Destination\n3) Origin and Destination\n4) Show all flights" << endl << ">> ";
			int s_option = 0;
			itrFlight bookedFlight;
			cin >> s_option;
			while (!(s_option == 1 || s_option == 2 || s_option == 3 || s_option == 4))
			{
				cout << "Please enter a valid option: ";
				cin >> s_option;
			}
			if (s_option == 1) // For searching flight by origin
			{
				string origin_city;
				cout << "Enter your origin city: ";
				cin >> origin_city;
				bookedFlight = airline.getFlightByOrigin(origin_city);
			}
			if (s_option == 2) //Search flight by Destination
			{
				string dest_city;
				cout << "Enter your destination city: ";
				cin >> dest_city;
				bookedFlight= airline.getFlightByDestination(dest_city);
			}
			if (s_option == 3) //Search flight by origin and destination
			{
				string dest_city, origin_city;
				cout << "Enter your destination city: ";
				cin >> dest_city;
				cout << "Enter your origin city: ";
				cin >> origin_city;
				bookedFlight = airline.getFlight(origin_city, dest_city);
			}
			if (s_option == 4) //Show all flights.
			{
				bookedFlight = airline.getFlight();
			}

			airline.bookFlight(bookedFlight, loggedIn); //Book a flight for logged in user.
			system("pause");
			break;
		}
		case '3':
		{
			system("cls");
			loggedIn->listBookedFlights();
			system("pause");
			break;
		}
		case '4':
		{
			system("cls");
			airline.editUser(loggedIn);
			system("pause");
			break;
		}
		case '5':
		{
			system("cls");
			airline.cancelFlight(loggedIn);
			system("pause");
			break;
		}
		case '6':
		{
			break;
		}
		default:
			cout << "Incorrect Option" << endl;
		}
		if (option == '6')
		{
			cout << "Exiting User section...";
			Sleep(1500);
			system("cls");
			break;
		}
	}
}

void admin_menu(AMS& airline)
{
	system("cls");
	for (int i = 0; i <= 100; i++)
		cout << "*";
	cout << "\n\n\t\t\t\tAdmin Panel" << "\n\n";
	for (int i = 0; i <= 100; i++)
		cout << "*";
	string user, pass;
	cout << "\n\n\n\n";
	cout << "\t\t\t\tUsername :  ";
	cin >> user;
	cout << "\n\n\t\t\t\tPassword: ";
	cin >> pass;
	if (user == USER_NAME && pass == PASSWORD)
	{
		
		while (1)
		{
			system("cls");
			for (int i = 0; i <= 100; i++)
				cout << "*";
			cout << "\n\n\t\t\t\tADMIN PANEL" << "\n\n";
			for (int i = 0; i <= 100; i++)
				cout << "*";
			
			cout << "\n\nWhat do you want to do?" << endl;
			cout << "1. Manage Flights\n2. Manage Passengers\n3. Exit";
			char option;
			cout << "\n\nEnter the corresponding number for the option: ";
			cin >> option;
			switch (option)
			{
			case '1':
			{
				system("cls");
				cout << "\t\t\tWelcome to Flight Management\n\nWhat do you want to do?" << endl;
				cout << "1. Add Flights\n2. Delete Flights\n3. Check Available Flights\n4. Show Passenger list\n5. Go back";
				char option1;
				cout << "\n\nEnter the corresponding number for the option: ";
				cin >> option1;
				if (option1 == '1')
				{
					airline.addFlight();
					airline.saveFlights("Flights.csv"); //update saved flights
					system("pause");
				}
				else if (option1 == '2')
				{
					airline.deleteFlight();
					airline.saveFlights("Flights.csv");//update saved flights
					system("pause");
				}
				else if (option1 == '3')
				{
					airline.displayFlights();
					system("pause");
				}
				else if (option1 == '4')
				{
					itrFlight flight = airline.getFlight();
					system("cls");
					flight->listPassengers();
					system("pause");

				}
				else if (option1 == '5')
				{
					cout << "Exiting Flight Management Section" << endl;
					Sleep(500);
				}
				else
					cout << "Incorrect Option" << endl;
				break;
			}
			case '2':
			{
				system("cls");
				cout << "Welcome to Passenger Management System\n\nWhat do you want to do?" << endl;
				cout << "1. Add Passengers\n2. Delete Passengers\n3. Check All Passengers\n4. Edit Passenger\n5. Go back";
				char option2;
				cout << "\n\nEnter the corresponding number for the option: ";
				cin >> option2;
				if (option2 == '1')
				{
					airline.addUser();
					airline.saveUsers("Users.csv"); //Update saved users.
					system("pause");
				}
				else if (option2 == '2')
				{
					airline.deleteUser();
					airline.saveUsers("Users.csv"); //Update saved users.
					system("pause");
				}
				else if (option2 == '3')
				{
					airline.listUsers();
					system("pause");
				}
				else if (option2 == '4')
				{
					cout << "\n1. Select account with CNIC";
					cout << "\n2. Select account with User ID";
					char option;
					cout << "\n\n>> ";
					cin >> option;
					itrPassenger editUser;
					if (option == '1')
					{
						string cnic;
						cout << " Enter your CNIC: ";
						cin >> cnic;
						editUser = airline.getUser(cnic);
					}
					else if (option == '2')
					{
						int id;
						cout << "Enter your User ID: ";
						cin >> id;
						editUser = airline.getUser(id);
					}
					else
					{
						cout << "Please enter a valid option." << endl;
						system("pause");
					}


					if (airline.checkUser(editUser))// Check if user login is valid.
					{
						airline.editUser(editUser);
						airline.saveUsers("Users.csv"); // Update saved users.
						system("pause");
					}
				}
				else if (option2 == '5')
				{
					cout << "Exiting Passenger Management Section" << endl;
					Sleep(500);
				}
				else
					cout << "Incorrect Option";
				break;
			}
			case '3':
				break;
			default:
				cout << "Incorrect option" << endl;
				break;
			}
			if (option == '3')
			{
				cout << "Exiting Admin Section...";
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}
	else
	{
		cout << "Incorrect Username/Password" << endl;
	}
}