#include <iostream>
#include "sortingAlgo.h"
using namespace std;

int main()
{
    int size = 5;
    int arr[size] = {65, 42, 89, 55, 30};
    bubbleSort(arr, size);

    printArr(arr, size);
}