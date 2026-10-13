// Task 3: Delivery Package Weights
// Algorithm: Selection Sort

// A delivery company wants to arrange five packages from lightest to heaviest before organizing them for transportation.

// Package weights (kg): 12, 5, 18, 3, 9

// Requirements:

// Store the package weights in an array.

// Sort the weights in ascending order using Selection Sort.

// Display the sorted weights.
#include <iostream>
using namespace std;
void selectionSort(int arr[], int size, char order = 'A')
{
    order = toupper(order);
    for (int i = 0; i < size - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < size; j++)
        {

            if ((arr[j] < arr[index] && order == 'A') || (arr[j] > arr[index] && order == 'D'))
            {
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size = 5;
    int arr[size] = {12, 5, 18, 3, 9};
    selectionSort(arr, size);

    printArr(arr, size);

    return 0;
}