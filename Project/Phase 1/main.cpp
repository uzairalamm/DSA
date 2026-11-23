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

int findFlightIndex(int id)
{
    for (int i = 0; i < flights.size(); i++)
    {
        if (flights[i].getFlightId() == id)
        {
            return i;
        }
    }
    return -1;
}

bool passengerExists(int id)
{
    for (int i = 0; i < passengers.size(); i++)
    {
        if (passengers[i].getPassengerId() == id)
        {
            return true;
        }
    }
    return false;
}

string getCityByCode(string code)
{
    for (int i = 0; i < airports.size(); i++)
    {
        if (airports[i].getCode() == code)
        {
            return airports[i].getCity();
        }
    }
    return "Unknown";
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
    if (findFlightIndex(id) != -1)
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

    if (from == to)
    {
        cout << "From and to airport cannot be the same." << endl;
        return;
    }

    cout << "Enter departure time (like 1430): ";
    cin >> time;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter total seats: ";
    cin >> seats;

    if (price <= 0 || seats <= 0)
    {
        cout << "Price and seats must be more than 0." << endl;
        return;
    }
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
        cout << "   (" << getCityByCode(flights[i].getFromCode())
             << " to " << getCityByCode(flights[i].getToCode()) << ")" << endl;
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
void bookSeat()
{
    int passengerId, flightId;

    cout << "Enter flight ID: ";
    cin >> flightId;
    int index = findFlightIndex(flightId);
    if (index == -1)
    {
        cout << "Flight not found." << endl;
        return;
    }

    if (!flights[index].hasSeats())
    {
        cout << "Flight is full." << endl;
        return;
    }

    cout << "Enter passenger ID: ";
    cin >> passengerId;
    if (!passengerExists(passengerId))
    {
        string name, phone;
        cout << "New passenger. Enter name: ";
        cin >> name;
        cout << "Enter phone: ";
        cin >> phone;

        Passenger newPassenger(passengerId, name, phone);
        passengers.push_back(newPassenger);
        cout << "Passenger added." << endl;
    }

    flights[index].addBooking();
    cout << "Seat booked." << endl;
}

void cancelSeat()
{
    int flightId;

    cout << "Enter flight ID: ";
    cin >> flightId;
    int index = findFlightIndex(flightId);
    if (index == -1)
    {
        cout << "Flight not found." << endl;
        return;
    }

    if (flights[index].getBookedSeats() > 0)
    {
        flights[index].removeBooking();
        cout << "Seat cancelled." << endl;
    }
    else
    {
        cout << "There are no bookings on this flight." << endl;
    }
}

void searchByRoute()
{
    string from, to;
    bool found = false;
    int cheapest = -1;

    cout << "Enter from airport code: ";
    cin >> from;
    cout << "Enter to airport code: ";
    cin >> to;

    for (int i = 0; i < flights.size(); i++)
    {
        if (flights[i].getFromCode() == from && flights[i].getToCode() == to)
        {
            flights[i].display();
            found = true;
            if (cheapest == -1 || flights[i].getPrice() < cheapest)
            {
                cheapest = flights[i].getPrice();
            }
        }
    }

    if (found)
    {
        cout << "Cheapest price on this route: " << cheapest << endl;
    }
    else
    {
        cout << "No direct flight found on this route." << endl;
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
        cout << "5. Book a seat" << endl;
        cout << "6. Cancel a seat" << endl;
        cout << "7. Search flights by route" << endl;
        cout << "8. Show passengers" << endl;
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
            bookSeat();
        else if (choice == 6)
            cancelSeat();
        else if (choice == 7)
            searchByRoute();
        else if (choice == 8)
            showPassengers();
        else if (choice == 0)
            cout << "Goodbye." << endl;
        else
            cout << "Wrong choice, try again." << endl;
    }

    return 0;
}