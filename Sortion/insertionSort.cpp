#include <iostream>
using namespace std;

void insertionSort(int *, int);
int main()
{
    int size = 10;
    int arr[size] = {91, 12, 23, 54, 62, 17, 48, 92, 100, 21};

    cout << "Before Sortion:\n";
    cout << "Array: {";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        cout << ((i < size - 1) ? ", " : "");
    }
    cout << "}\n";

    insertionSort(arr, size);

    cout << "After Sortion:\n";
    cout << "Array: {";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        cout << ((i < size - 1) ? ", " : "");
    }
    cout << "}\n";
}

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
};