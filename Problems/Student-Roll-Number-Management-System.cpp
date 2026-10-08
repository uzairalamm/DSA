/*
========================================================
       STUDENT ROLL NUMBER MANAGEMENT SYSTEM
========================================================

Create a program to manage student roll numbers using
a fixed-size array.

MAIN REQUIREMENTS:

1. Use a fixed-size array with a capacity of 10.

2. Maintain a separate variable called `size` to keep
   track of how many roll numbers are currently stored.

3. The program must provide a menu:

   1. Display All Roll Numbers
   2. Insert Roll Number
   3. Delete Roll Number
   4. Search Roll Number
   5. Exit

--------------------------------------------------------
INSERTION REQUIREMENTS
--------------------------------------------------------

4. Ask the user for:
      - Roll number
      - Position where the roll number should be inserted

5. User positions must start from 1.

6. Internally, convert the user's position to a
   0-based array index.

7. Before inserting:
      - Check whether the array is full.
      - Check whether the position is valid.

8. When inserting, shift existing elements one position
   to the right.

9. Increase `size` after successful insertion.

10. Do not allow duplicate roll numbers.

--------------------------------------------------------
DELETION REQUIREMENTS
--------------------------------------------------------

11. Ask the user for the position of the student to delete.

12. User positions must start from 1.

13. Before deleting:
      - Check whether the array is empty.
      - Check whether the position is valid.

14. When deleting, shift the elements after that position
   one position to the left.

15. Decrease `size` after successful deletion.

--------------------------------------------------------
SEARCH REQUIREMENTS
--------------------------------------------------------

16. Ask the user for a roll number to search.

17. Search the array manually using a loop.

18. If found, display:
      - Roll number
      - Its position

19. If not found, display an appropriate message.

--------------------------------------------------------
DISPLAY REQUIREMENTS
--------------------------------------------------------

20. Display only the elements from index 0 to size - 1.

21. If the array is empty, display an appropriate message.

--------------------------------------------------------
MENU REQUIREMENTS
--------------------------------------------------------

22. The menu must continue running until the user
   selects Exit.

23. Handle invalid menu choices.

24. Handle invalid positions such as:
      - 0
      - negative numbers
      - position greater than the current size
      - position greater than the allowed insertion position

25. Do not allow insertion when the array is full.

26. Do not allow deletion when the array is empty.

--------------------------------------------------------
C++ / DESIGN REQUIREMENTS
--------------------------------------------------------

27. Do NOT use vector.

28. Do NOT use list.

29. Do NOT use any built-in container for storing
    the roll numbers.

30. Use functions to separate the operations.

31. Use a constant for the array capacity.

32. `size` must represent the number of actual
    roll numbers currently stored.

33. Do not hardcode the current size inside functions.

34. The insertion and deletion logic must be implemented
    manually using loops.

35. You may use a class to organize the program.

36. If you use a class, keep the array, size, and capacity
    as appropriate data members and make the operations
    member functions.

37. Keep the program organized and readable.

========================================================
*/

#include <iostream>
#include <limits>
using namespace std;

void rollNo_Insertion(int *arr, int &size, int capacity, int rollNo, int position);
void rollNo_Deletion(int *arr, int &size, int position);
void rollNo_Search(int *arr, int size, int rollNo);
void rollNo_Display(int *arr, int size);
bool check_Dublicate(int *arr, int size, int rollNo);
template <typename T>
bool inputValidation(T &input);

int main()
{
    int arr[10] = {101, 103, 104, 105};
    int size{4}, rollNo{}, pos{};
    int choice{};

    do
    {
        cout << "\n===================================================\n";
        cout << "1. Display All Roll Numbers\n";
        cout << "2. Insert Roll Number\n";
        cout << "3. Delete Roll Number\n";
        cout << "4. Search Roll Number\n";
        cout << "5. Exit \n";
        cout << "Enter Your Choice: ";
        do
        {
            if (inputValidation<int>(choice))
                break;
            cout << "Invalid Input! Please Enter a Valid Choice: ";
        } while (true);

        switch (choice)
        {
        case 1:
            rollNo_Display(arr, size);
            break;

        case 2:
            cout << "Enter RollNo: ";
            do
            {
                if (inputValidation<int>(rollNo))
                    break;
                cout << "Invalid Input! Please Enter a Valid Roll Number: ";
            } while (true);

            if (check_Dublicate(arr, size, rollNo))
            {
                cout << "Roll Number Already Exists!\n";
                break;
            }

            cout << "Enter The Position (1 - " << size + 1 << "): ";
            do
            {
                if (inputValidation<int>(pos))
                    break;
                cout << "Invalid Input! Please Enter a Valid Position: ";
            } while (true);

            rollNo_Insertion(arr, size, 10, rollNo, pos - 1);
            break;

        case 3:
            cout << "Enter The Position (1 - " << size << "): ";
            do
            {
                if (inputValidation<int>(pos))
                    break;
                cout << "Invalid Input! Please Enter a Valid Position: ";
            } while (true);

            rollNo_Deletion(arr, size, pos - 1);
            break;

        case 4:
            cout << "Enter the Roll Number: ";
            do
            {
                if (inputValidation<int>(rollNo))
                    break;
                cout << "Invalid Input! Please Enter a Valid Roll Number: ";
            } while (true);

            rollNo_Search(arr, size, rollNo);
            break;
        case 5:
            cout << "Exiting......................\n";
            break;

        default:
            cout << "Please Enter Only (1-5)\n";
        }
    } while (choice != 5);
}

void rollNo_Insertion(int *arr, int &size, int capacity, int rollNo, int position)
{

    if (size >= capacity)
    {
        cout << "Array is Full, Cannot insert Another Element!\n";
        return;
    }

    if (position < 0 || position > size)
    {
        cout << "Invalid Position!\n";
        return;
    }

    for (int i = size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = rollNo;
    size++;
}

void rollNo_Deletion(int *arr, int &size, int position)
{
    if (size <= 0)
    {
        cout << "Array is Empty!";
        return;
    }

    if (position < 0 || position >= size)
    {
        cout << "Cannot Perform Deletion!\n";
        return;
    }

    else if (position == size - 1)
    {
        size--;
        return;
    }
    else
    {
        for (int i = position; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

void rollNo_Search(int *arr, int size, int rollNo)
{
    for (int i = 0; i < size; i++)
    {
        if (rollNo == arr[i])
        {
            cout << "Roll Number Found At Position: " << i + 1 << endl;
            return;
        }
    }
    cout << "Roll Number Not Found!\n";
}

void rollNo_Display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

bool check_Dublicate(int *arr, int size, int rollNo)
{
    for (int i = 0; i < size; i++)
    {
        if (rollNo == arr[i])
            return true;
    }
    return false;
}
template <typename T>
bool inputValidation(T &input)
{

    cin >> input;
    if (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}