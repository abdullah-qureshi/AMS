#include "AMS.h"
#include <iostream>

int main()
{
    AMS PakistanAirLines;
    PakistanAirLines.addFlight(260, "Lahore", "Okara", 69, 4200);
    PakistanAirLines.addFlight(263, "Lahore", "Islamabad", 75, 4200);
    PakistanAirLines.addFlight(711, "Islamabad", "Riyadh", 150, 4200);
    PakistanAirLines.addFlight(262, "Berlin", "Monaco", 210, 4200);
    system("pause");
    system("cls");

    PakistanAirLines.addUser("Abdullah", "Qureshi", "3520231918387", "03216970819", "abureshi2001@gmail.com");
    PakistanAirLines.addUser("Sohaib", "Sheikh", "35202121313131", "032171502031", "sohaib2001@gmail.com");
    PakistanAirLines.addUser("Muaaz", "Irfan", "3520231451320", "096587878777", "muaaz2001@gmail.com");
    system("pause");
    system("cls");

    PakistanAirLines.listUsers();
    PakistanAirLines.displayFlights();
    system("pause");
    system("cls");

    PakistanAirLines.bookFlight(PakistanAirLines.getFlight(), PakistanAirLines.getUser("3520231918387")); 
    system("pause");
    system("cls");
    PakistanAirLines.getUser("3520231918387")->listBookedFlights();

}
