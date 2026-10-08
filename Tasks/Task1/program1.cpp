#include <iostream>
using namespace std;

int main()
{
    int num{};

    cout << "Enter an Integer: ";
    cin >> num;
    int *ptr = &num;

    system("cls");
    cout << "Value of Num: " << num << endl;
    cout << "Address of Num: " << &num << endl;
    cout << "Value of Ptr: " << ptr << endl;
    cout << "Value of Num access through Ptr: " << *ptr << endl;

    return 0;
}