#include <iostream>
using namespace std;

int main()
{
    int size = 8;
    int arr[size] = {10, 20, 30, 40, 50, 60, 70, 80};

    size--;
    cout << "Elements in ARRAY: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}