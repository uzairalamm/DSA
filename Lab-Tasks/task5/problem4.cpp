// Task 4: University Quiz Results
// Algorithms: Bubble Sort and Selection Sort

// A university teacher wants to arrange students' quiz scores from highest to lowest.

// Quiz scores: 72, 45, 90, 60, 35

// Requirements:

// Sort the scores in descending order using Bubble Sort.

// Sort the same scores in descending order using Selection Sort.

// Display the sorted array for each algorithm.
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
void bubbleSort(int arr[], int size, char order = 'A')
{
    order = toupper(order);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if ((arr[j] > arr[j + 1] && order == 'A') || (arr[j] < arr[j + 1] && order == 'D'))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    int arr[size] = {72, 45, 90, 60, 35};
    cout << "Using Selection Sort!\n";
    selectionSort(arr, size, 'D');
    printArr(arr, size);

    cout << "Using Bubble Sort!\n";
    bubbleSort(arr, size, 'D');
    printArr(arr, size);

    return 0;
}