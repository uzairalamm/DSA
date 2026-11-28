#include <iostream>
#include <stdexcept>
using namespace std;

// Basic of stack
// void pushElement(int arr[], int size, int &top, int value)
// {
//     if (top == size - 1)
//     {
//         cout << "Stack is Full\n";
//         return;
//     }

//     top++;
//     arr[top] = value;
//     cout << value << " is added to the Stack\n";
// }
// void popElement(int arr[], int &top)
// {
//     if (top == -1)
//     {
//         cout << "Stack is empty\n";
//         return;
//     }
//     cout << arr[top] << " is removed\n";
//     top--;
// }

// void peekElement(int arr[], int top)
// {
//     if (top == -1)
//     {
//         cout << "Stack is empty\n";
//         return;
//     }
//     cout << "Top element is: " << arr[top] << endl;
// }

// bool isEmpty(int top)
// {
//     if (top == -1)
//         return true;
//     return false;
// }

// int main()
// {
//     const int SIZE = 2;
//     int stack[SIZE];
//     int top = -1;

//     pushElement(stack, SIZE, top, 10);
//     pushElement(stack, SIZE, top, 20);
//     peekElement(stack, top);
//     popElement(stack, top);
//     popElement(stack, top);
// }

// Now we create it using Class
// class Stack
// {
//     static const int CAPACITY = 10;
//     int stack[CAPACITY];
//     int top;

// public:
//     Stack() : top(-1) {}
//     void pushElement(int value);
//     void popElement();
//     bool isEmpty();
//     void peekElement();
//     void display();
// };

// void Stack::pushElement(int value)
// {
//     if (top == CAPACITY - 1)
//     {
//         cout << "Stack Overflow\n";
//         return;
//     }
//     top++;
//     stack[top] = value;
// }

// void Stack::popElement()
// {
//     if (isEmpty())
//     {
//         cout << "Stack UnderFlow\n";
//         return;
//     }
//     top--;
// }
// bool Stack::isEmpty()
// {
//     if (top == -1)
//         return true;
//     return false;
// }

// void Stack::peekElement()
// {
//     if (isEmpty())
//     {
//         cout << "Stack is Empty\n";
//         return;
//     }
//     cout << stack[top];
// }

// void Stack::display()
// {
//     if (isEmpty())
//     {
//         cout << "Stack is Empty\n";
//         return;
//     }

//     for (int i = top; i >= 0; i--)
//     {
//         cout << stack[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     Stack stack;
//     cout << boolalpha << stack.isEmpty() << endl;
//     stack.peekElement();
//     stack.pushElement(120);
//     stack.pushElement(310);
//     stack.display();
//     stack.popElement();
//     stack.display();
// }
