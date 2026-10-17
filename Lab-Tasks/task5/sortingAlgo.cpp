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
void merge(int arr[], int start, int middle, int end)
{
    int n1 = middle + 1 - start;
    int n2 = end - middle;

    int arr1[n1];
    int arr2[n2];

    for (int i = 0; i < n1; i++)
        arr1[i] = arr[start + i];

    for (int j = 0; j < n2; j++)
        arr2[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int middle = start + (end - start) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
