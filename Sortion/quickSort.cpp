#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot{arr[end]}, index = start - 1;

    for (int i = start; i < end; i++)
    {
        if (arr[i] >= pivot)
        {
            index++;
            swap(arr[i], arr[index]);
        }
    }
    index++;
    swap(arr[index], arr[end]);
    return index;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main()
{
    int arr[5] = {3, 4, 1, 2, 5};
    quickSort(arr, 0, 4);
    for (int num : arr)
    {
        cout << num << ' ';
    }
    cout << endl;
}