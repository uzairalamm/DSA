#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
using namespace std;

class Passenger
{
private:
    int passengerId;
    string name;
    string phone;

public:
    Passenger() : passengerId(0000), name("Unknown"), phone("Unknown") {}
    Passenger(int id, string passengerName, string passengerPhone)
    {
        passengerId = id;
        name = passengerName;
        phone = passengerPhone;
    }

    int getPassengerId()
    {
        return passengerId;
    }

    void display()
    {
        cout << "Passenger " << passengerId << ": " << name << " | " << phone << endl;
    }
};

#endif