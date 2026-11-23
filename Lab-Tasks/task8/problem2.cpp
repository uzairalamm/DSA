#include <iostream>
using namespace std;

int linearSearch(int bookIds[], int size, int searchId)
{
    for (int i = 0; i < size; i++)
    {
        if (bookIds[i] == searchId)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int bookIds[6] = {105, 110, 115, 120, 125, 130};
    int size = 6;

    int position = linearSearch(bookIds, size, 120);
    if (position != -1)
    {
        cout << "Book ID 120 found at position " << position << endl;
    }
    else
    {
        cout << "Book ID 120 does not exist" << endl;
    }

    position = linearSearch(bookIds, size, 140);
    if (position != -1)
    {
        cout << "Book ID 140 found at position " << position << endl;
    }
    else
    {
        cout << "Book ID 140 does not exist" << endl;
    }

    return 0;
}