// A student places books one above another. The books are represented by values 10, 20, 30.
// Write a C++ program using an array to:
// Insert all three values using Push.
// Display the stack.
// Remove the top element using Pop.
// Display the remaining elements.
// Show the top element using Peek.

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

    pushElement(stack, SIZE, top, 10);
    pushElement(stack, SIZE, top, 20);
    pushElement(stack, SIZE, top, 30);
    display(stack, top);
    popElement(stack, top);
    display(stack, top);
}