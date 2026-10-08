#include <iostream>
using namespace std;

int main()
{
    int num{};

    cout << "Enter an Integer: ";
    cin >> num;
    int *ptr = &num;

    cout << "Value Before Change: " << num << endl;
    *ptr = 90;
    cout << "Value After Change: " << num << endl;

    return 0;
}