#include <iostream>
using namespace std;

void merge(int arr[], int start, int end, int middle)
{
    int n1 = middle + 1;
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
        else if (arr2[j] <= arr1[i])
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
        merge(arr, start, end, middle);
    }
}

int main()
{
    int arr[5] = {1, 31, 22, 52, 2};
    int start = 0;
    int last = sizeof(arr) / sizeof(arr[0]) - 1;

    mergeSort(arr, start, last);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}