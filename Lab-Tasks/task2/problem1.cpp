// Task 1 : Create a structure named Student with two members : name and age.Create one variable of the structure and display its values.

#include <iostream>
using namespace std;

struct General
{
    string name{};
    int age{};
} myStruct;

int main()
{
    myStruct.age = 12;
    myStruct.name = "ALI";

    cout << "Name: " << myStruct.age
         << "\nAge: " << myStruct.name << endl;
}