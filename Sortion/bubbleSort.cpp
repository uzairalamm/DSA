#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size, int choice = 1)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if ((choice == 1 && arr[j] > arr[j + 1]) || (choice == 2 && arr[j] < arr[j + 1]))
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
    cout << "{";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        cout << ((i < size - 1) ? ", " : "");
    }
    cout << "}\n";
}

int main()
{
    const int SIZE = 5;
    int arr[SIZE] = {51, 24, 14, 2, 31};
    int choice;

    cout << "===================== Bubble Sort Algorithm =====================\n";
    cout << "1. Ascending Order\n2. Descending Order\n3. Exit\n";

    while (choice != 3)
    {
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Sorted in Ascending Order\n";
            bubbleSort(arr, SIZE, choice);
            printArr(arr, SIZE);
            break;

        case 2:
            cout << "Sorted in Descending Order\n";
            bubbleSort(arr, SIZE, choice);
            printArr(arr, SIZE);
            break;

        case 3:
            cout << "Existing........\n";
            break;

        default:
            cout << "Invalid Choice! Please Choice Between 1-3\n";
            break;
        }
    }
    return 0;
}