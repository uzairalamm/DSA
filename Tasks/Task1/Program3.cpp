#include <iostream>
using namespace std;

int main()
{
    int num1{}, num2;

    cout << "Enter an Two Integer: ";
    cin >> num1 >> num2;
    int *ptr1 = &num1, *ptr2 = &num2;

    system("cls");

    int sum, diff, product;
    sum = *ptr1 + *ptr2;
    diff = *ptr1 - *ptr2;
    product = *ptr1 * *ptr2;

    cout << "Sum        : " << sum << endl;
    cout << "Difference : " << diff << endl;
    cout << "Product    : " << product << endl;

    return 0;
}