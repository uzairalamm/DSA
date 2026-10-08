#include <iostream>
using namespace std;

void takeInput(int arr[], int size)
{
    cout << "Enter " << size << " Numbers: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printRequirdElement(int arr[], int size)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (smallest > arr[i])
            smallest = arr[i];

        if (largest < arr[i])
            largest = arr[i];
    }

    cout << "Largest: " << largest << endl;
    cout << "Smallest: " << smallest << endl;
}

int main()
{
    int size = 5;
    int arr[size];

    takeInput(arr, size);
    system("cls");
    printArr(arr, size);
    printRequirdElement(arr, size);
}