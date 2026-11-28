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
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    myStack.display();

    cout << "Top element: " << myStack.peek() << endl;

    myStack.pop();

    cout << "After pop:" << endl;

    myStack.display();

    return 0;
}