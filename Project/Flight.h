#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
using namespace std;

class Flight
{
    int flightId;
    string fromCode;
    string toCode;
    int departureTime;
    int price;
    int bookedSeats;
    int totalSeats;

public:
    Flight() : flightId(0000), fromCode("******"), toCode("******"), departureTime(0000),
               price(0000), bookedSeats(0), totalSeats(0) {};

    Flight(int id, string from, string to, int time, int flightPrice, int seats) : flightId(id), fromCode(from), toCode(to), departureTime(time),
                                                                                   price(flightPrice), bookedSeats(0), totalSeats(seats) {};

    string getFromCode() const { return fromCode; }
    string getToCode() const { return toCode; }

    int getFlightId() const { return flightId; }
    int getDepartureTime() const { return departureTime; }
    int getPrice() const { return price; }
    int getBookedSeats() { return bookedSeats; }

    void addBooking() { bookedSeats++; }
    void removeBooking() { bookedSeats--; }
    bool hasSeats() const { return bookedSeats < totalSeats; }

    void display()
    {
        cout << "Flight " << flightId << ": " << fromCode << " -> " << toCode
             << " | Time: " << departureTime
             << " | Price: " << price
             << " | Seats: " << bookedSeats << "/" << totalSeats << endl;
    }
};
#endif