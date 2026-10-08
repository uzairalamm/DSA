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

void printRequirement(int arr[], int size)
{
    int evenCount{}, oddCount{};

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
            evenCount++;

        else
            oddCount++;
    }
    cout << "Even Count: " << evenCount << endl;
    cout << "Odd Count: " << evenCount << endl;
}

int main()
{
    int size = 10;
    int arr[size];

    takeInput(arr, size);
    system("cls");
    printRequirement(arr, size);
}