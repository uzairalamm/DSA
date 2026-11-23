#include <iostream>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertAtPos(int arr[], int &size, int pos, int value)
{
    if (pos < 1 || pos > size + 1)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    for (int i = size; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    size++;
}

void deleteAtPos(int arr[], int &size, int pos)
{
    if (pos < 1 || pos > size)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    for (int i = pos - 1; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
int search(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return i + 1;
    }
    return -1;
}

int main()
{
    int quantities[10] = {10, 20, 15, 30, 25};
    int size = 5;

    // 1. Display all quantities
    cout << "All quantities:" << endl;
    printArr(quantities, size);

    // 2. Insert 18 at position 3
    insertAtPos(quantities, size, 3, 18);

    // 3. Delete the element at position 2
    deleteAtPos(quantities, size, 2);
    printArr(quantities, size);

    // 4. Search for quantity 30
    int pos = search(quantities, size, 30);
    if (pos != -1)
        cout << "Quantity 30 found at position: " << pos << endl;
    else
        cout << "Quantity 30 not found" << endl;

    // 5. Display the updated array
    printArr(quantities, size);
    return 0;
}