// A stack has a maximum capacity of 5 elements.
//     Write a C++ program to :
//     Insert five elements into the stack.
//     Try to insert a sixth element and display Stack Overflow.
//     Remove all elements one by one.
//     Try to remove another element and display Stack Underflow.

#include <iostream>
using namespace std;

void pushElement(int arr[], int size, int &top, int value)
{
    if (top == size - 1)
    {
        cout << "Stack is Full\n";
        return;
    }

    top++;
    arr[top] = value;
    cout << arr[top] << " added to the Stack\n";
}

void popElement(int arr[], int &top)
{
    if (top == -1)
    {
        cout << "Stack is Empty\n";
        return;
    }
    cout << arr[top] << " removed from the stack\n";
    top--;
}

void display(int arr[], int &top)
{
    if (top == -1)
    {
        cout << "Stack is Empty\n";
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int SIZE = 5;
    int stack[SIZE];
    int top = -1;

    for (int i = 0; i < SIZE; i++)
        pushElement(stack, SIZE, top, (i + 1) * 10);
    pushElement(stack, SIZE, top, 60);

    display(stack, top);

    for (int i = 0; i < SIZE; i++)
        popElement(stack, top);
    popElement(stack, top);

    display(stack, top);
}