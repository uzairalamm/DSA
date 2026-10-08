#include <iostream>
using namespace std;

// // void insertElement(int *arr, int &size, int pos, int value)
// // {
// //     for (int i = size; i > pos; i--)
// //     {
// //         arr[i] = arr[i - 1];
// //     }
// //     arr[pos] = value;
// //     size++;
// // }

// void insertElement(int *&arr, int &size, int pos, int value)
// {
//     int newSize = size + 1;
//     int *newArr = new int[newSize];

//     for (int i = 0; i < size; i++)
//     {
//         newArr[i] = arr[i];
//     }

//     for (int i = size; i > pos; i--)
//     {
//         newArr[i] = newArr[i - 1];
//     }

//     newArr[pos] = value;
//     arr = newArr;
//     size = newSize;
// }

// void deleteElement(int *arr, int &size, int pos)
// {
//     if (pos == size)
//     {
//         size--;
//     }
//     else if (pos > size)
//     {
//         cout << "Invalid Position\n";
//     }
//     else
//     {

//         for (int i = pos; i < size - 1; i++)
//         {
//             arr[i] = arr[i + 1];
//         }
//         size--;
//     }
// }

// int main()
// {
//     int size = 5;
//     int *arr = new int[size]{1, 2, 3, 4, 5};

//     insertElement(arr, size, 2, 10);

//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     cout << "\nAfter Deletion\n";
//     deleteElement(arr, size, 2);
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     delete[] arr;
// }

// -------------------------------------------------------------------------------------------------
void insertElement(int *arr, int &size, int capacity, int pos, int value)
{
    if (size >= capacity)
    {
        cout << "Array is Full, Cannot Operate Any Operation!\n";
        return;
    }

    for (int i = size; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    size++;
}

void deleteElement(int *arr, int &size, int pos)
{
    if (pos < 0 || pos >= size)
    {
        cout << "Invalid Position!\n";
        return;
    }
    else
    {
        for (int i = pos; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

int main()
{
    int arr[10] = {10, 20, 30, 40};
    int size = 4;
    int pos = 4;

    insertElement(arr, size, 10, pos, 25);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    deleteElement(arr, size, pos);
    cout << "After Deletion!\n";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
