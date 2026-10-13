// I donot know how to use module right now, but i will in few days. i hope so... then i will update the code in my problems

#include "sortingAlgo.h"
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int size, char order)
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

void selectionSort(int arr[], int size, char order)
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