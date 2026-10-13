// Task 2: Supermarket Price Arrangement
// A supermarket manager wants to arrange product prices from highest to lowest to identify the cheapest products.

// Product prices: 450, 120, 300, 80, 250

// Requirements:

// Store the prices in an array.

// Sort the prices in descending order using Selection Sort.

// Display the sorted prices.
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
    int arr[size] = {450, 120, 300, 80, 250};
    selectionSort(arr, size, 'D');

    printArr(arr, size);

    return 0;
}