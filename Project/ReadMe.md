# Airline Reservation System

## About the Project

This is a console based airline reservation system written in C++. It is our Data Structures and Algorithms class project. The program works like a small version of an airline booking system. The user can add airports and flights, book and cancel seats, and search flights between two cities.

We are building it phase by phase. Each new phase adds a new data structure and a new feature.

## Current Status

Phase 1 is done. The basic classes and the menu are working. Tickets, waiting list, sorting and route finding will come in the next phases.

## Features (Phase 1)

- Add and show airports
- Add and show flights
- Book a seat on a flight (a new passenger is added automatically if the ID is new)
- Cancel a seat
- Search flights between two airports and show the cheapest price
- Show all passengers
- Checks for wrong input, like duplicate IDs, unknown airports, same from and to airport, and a full flight

## Planned Features

- Tickets with Economy and Business types (inheritance and polymorphism)
- Search a ticket by ID using a hash table
- Waiting list for full flights using a queue
- Flights sorted by price using a BST
- Route finding with connecting flights using a graph (BFS and Dijkstra)
- Save and load data from files
- Exception handling

## Classes

- **Airport:** stores code, name and city
- **Flight:** stores flight ID, from and to codes, departure time, price, total seats and booked seats
- **Passenger:** stores passenger ID, name and phone

## Project Files

- `main.cpp` has the menu and the main functions
- `Airport.h` has the Airport class
- `Flight.h` has the Flight class
- `Passenger.h` has the Passenger class

## How to Run

Open the terminal inside the project folder and run:

```
g++ main.cpp -o airline
./airline
```

On Windows, run `airline.exe` instead of `./airline`.

## Menu

```
1. Add airport
2. Show airports
3. Add flight
4. Show flights
5. Book a seat
6. Cancel a seat
7. Search flights by route
8. Show passengers
0. Exit
```

## Notes

- Type names without spaces (for example `Allama_Iqbal`), because the program reads input with `cin >>`, which stops at a space.
- Departure time is entered as a number like 1430.
- Cancelling a seat only reduces the seat count for now. It will be linked to real tickets in Phase 2.

## Concepts Used

- Classes and objects
- Encapsulation (private data with getters)
- Constructors
- Vectors
- Loops and input checking

## Group Members

- Name 1
- Name 2
- Name 3

## Summary

This project is a small airline booking program built step by step. Phase 1 gives us the base classes and a working menu. The next phases will add tickets, a waiting list, sorting and route finding using the data structures from our class.
