#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
using namespace std;

class Airport
{
    string name;
    string city;
    string code;

public:
    Airport() : name("unknown"), city("unknown"), code("******") {}
    Airport(string airportCode, string airportName, string airportCity)
        : name(airportName), city(airportCity), code(airportCode) {}

    string getName() const { return name; }
    string getCity() const { return city; }
    string getCode() const { return code; }

    void display() const
    {
        cout << code << " - " << name << " (" << city << ")" << endl;
    }
};

#endif