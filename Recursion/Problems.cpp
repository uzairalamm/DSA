#include <iostream>
using namespace std;

int fact(int);
int countDown(int);
int pow(int, int);
int fibonaci(int);
void reverseDigit(int);

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Factorial
    cout << "Factorial of " << num << " is: " << fact(num) << endl;

    // count Down
    cout << "Countdown: ";
    countDown(num);

    // power
    cout << "Power of " << num << " is: " << pow(num, 2) << endl;

    // fibonaci
    cout << "Fibonaci of " << num << "th term is: " << endl;
    for (int i = 1; i <= num; i++)
    {
        cout << fibonaci(i) << " ";
    }
    cout << endl;

    // reverse Digit
    reverseDigit(num);
    return 0;
}

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * fact(n - 1);
}

int countDown(int n)
{
    if (n < 0)
    {
        cout << "Invalid input. Please enter a non-negative integer." << endl;
        return -1; // Indicate an error
    }
    if (n == 0)
    {
        cout << "\nCountdown complete!" << endl;
        return 0;
    }
    cout << n << " ";
    return countDown(n - 1);
}

int pow(int base, int exp)
{
    if (exp == 0)
        return 1;
    return base * pow(base, exp - 1);
}

int fibonaci(int n)
{
    if (n <= 1)
        return n;

    return fibonaci(n - 1) + fibonaci(n - 2);
}

void reverseDigit(int num)
{
    if (num == 0)
        return;
    cout << num % 10;
    reverseDigit(num / 10);
}