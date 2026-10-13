// Task 1: Student Marks Management
// A teacher wants to arrange the marks of five students from lowest to highest.

//     Given marks : 65, 42, 89, 55, 30

//                 Requirements :

//     Store the marks in an array.

//     Sort the marks in ascending order using Bubble Sort.

//     Display the sorted array.

//     Display the array after each pass.
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int size, char order = 'A')
{
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
    int arr[size] = {65, 42, 89, 55, 30};
    bubbleSort(arr, size);

    printArr(arr, size);

    return 0;
}