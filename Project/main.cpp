#include <iostream>
#include <vector>
#include <string>
#include "Airport.h"
#include "Flight.h"
#include "Passenger.h"
using namespace std;

vector<Airport> airports;
vector<Flight> flights;
vector<Passenger> passengers;

bool airportExists(string code)
{
    for (int i = 0; i < airports.size(); i++)
    {
        if (airports[i].getCode() == code)
        {
            return true;
        }
    }
    return false;
}

bool flightExists(int id)
{
    for (int i = 0; i < flights.size(); i++)
    {
        if (flights[i].getFlightId() == id)
        {
            return true;
        }
    }
    return false;
}

void addAirport()
{
    string code, name, city;
    cout << "Enter airport code (like LHE): ";
    cin >> code;
    if (airportExists(code))
    {
        cout << "This airport already exists." << endl;
        return;
    }
    cout << "Enter airport name: ";
    cin >> name;
    cout << "Enter city: ";
    cin >> city;

    Airport newAirport(code, name, city);
    airports.push_back(newAirport);
    cout << "Airport added." << endl;
}

void showAirports()
{
    if (airports.empty())
    {
        cout << "No airports yet." << endl;
        return;
    }
    for (int i = 0; i < airports.size(); i++)
    {
        airports[i].display();
    }
}

void addFlight()
{
    int id, time, price, seats;
    string from, to;

    cout << "Enter flight ID: ";
    cin >> id;
    if (flightExists(id))
    {
        cout << "This flight ID is already used." << endl;
        return;
    }
    cout << "Enter from airport code: ";
    cin >> from;
    cout << "Enter to airport code: ";
    cin >> to;
    if (!airportExists(from) || !airportExists(to))
    {
        cout << "Airport not found. Add the airport first." << endl;
        return;
    }
    cout << "Enter departure time (like 1430): ";
    cin >> time;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter total seats: ";
    cin >> seats;

    Flight newFlight(id, from, to, time, price, seats);
    flights.push_back(newFlight);
    cout << "Flight added." << endl;
}

void showFlights()
{
    if (flights.empty())
    {
        cout << "No flights yet." << endl;
        return;
    }
    for (int i = 0; i < flights.size(); i++)
    {
        flights[i].display();
    }
}

void addPassenger()
{
    int id;
    string name, phone;

    cout << "Enter passenger ID: ";
    cin >> id;
    for (int i = 0; i < passengers.size(); i++)
    {
        if (passengers[i].getPassengerId() == id)
        {
            cout << "This passenger ID is already used." << endl;
            return;
        }
    }
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone: ";
    cin >> phone;

    Passenger newPassenger(id, name, phone);
    passengers.push_back(newPassenger);
    cout << "Passenger added." << endl;
}

void showPassengers()
{
    if (passengers.empty())
    {
        cout << "No passengers yet." << endl;
        return;
    }
    for (int i = 0; i < passengers.size(); i++)
    {
        passengers[i].display();
    }
}

int main()
{
    int choice = -1;

    while (choice != 0)
    {
        cout << endl;
        cout << "===== Airline Reservation System =====" << endl;
        cout << "1. Add airport" << endl;
        cout << "2. Show airports" << endl;
        cout << "3. Add flight" << endl;
        cout << "4. Show flights" << endl;
        cout << "5. Add passenger" << endl;
        cout << "6. Show passengers" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            addAirport();
        else if (choice == 2)
            showAirports();
        else if (choice == 3)
            addFlight();
        else if (choice == 4)
            showFlights();
        else if (choice == 5)
            addPassenger();
        else if (choice == 6)
            showPassengers();
        else if (choice == 0)
            cout << "Goodbye." << endl;
        else
            cout << "Wrong choice, try again." << endl;
    }

    return 0;
}