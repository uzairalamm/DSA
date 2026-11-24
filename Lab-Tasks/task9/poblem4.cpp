// A text editor stores recent actions in a stack. The actions are represented by values 10, 20, 30.
// Write a C++ program using a linked list to:
// Insert all actions using Push.
// Display all actions.
// Perform two Undo operations using Pop.
// Display the remaining actions.
// Show the top element using Peek.

#include <iostream>
using namespace std;

class Node
{
public:
    int action;
    Node *next;

    Node(int action)
    {
        this->action = action;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int action)
    {
        Node *newNode = new Node(action);

        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node *temp = top;
        cout << "Undo action: " << top->action << endl;

        top = top->next;
        delete temp;
    }

    void peek()
    {
        if (top == nullptr)
        {
            cout << "No actions remaining!" << endl;
            return;
        }

        cout << "Top action: " << top->action << endl;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "No actions remaining!" << endl;
            return;
        }

        Node *currentNode = top;

        cout << "Actions (Top to Bottom): ";

        while (currentNode != nullptr)
        {
            cout << currentNode->action << " ";
            currentNode = currentNode->next;
        }

        cout << endl;
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Stack editor;

    // Insert all actions
    editor.push(10);
    editor.push(20);
    editor.push(30);

    // Display all actions
    cout << "Initial Actions:" << endl;
    editor.display();

    // Perform two Undo operations
    cout << "\nPerforming Two Undo Operations:" << endl;
    editor.pop();
    editor.pop();

    // Display remaining actions
    cout << "\nRemaining Actions:" << endl;
    editor.display();

    // Show top element
    cout << endl;
    editor.peek();

    return 0;
}
