#include <iostream>
using namespace std;

int main()
{
    int size = 8;
    int arr[size] = {10, 20, 30, 40, 50, 60, 70, 80};

    int pos = 0;

    cout << "Elements in ARRAY: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    for (int i = size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = 5;
    size++;

    cout << "After Insertion in ARRAY: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    for (int i = pos; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;

    cout << "After Deletion in ARRAY: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}