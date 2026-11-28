#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
};

class Stack
{
    Node *top;

public:
    Stack() : top(nullptr) {}
    void pushElement(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    void popElement()
    {
        if (top == nullptr)
        {
            cout << "Stack is Empty\n";
            return;
        }
        Node *nodeToDel = top;
        top = top->next;
        delete nodeToDel;
    }
    bool isEmpty() const { return top == nullptr; }

    int peek() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return top->data;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node *currentNode = top;

        cout << "Stack elements:" << endl;

        while (currentNode != nullptr)
        {
            cout << currentNode->data << endl;

            currentNode = currentNode->next;
        }
    }
};
