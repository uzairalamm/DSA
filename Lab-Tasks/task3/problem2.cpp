#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;

int main()
{
    Node *currentNode = NULL;

    for (int i = 2; i <= 10; i += 2)
    {
        Node *newNode = new Node;
        newNode->data = i * 10;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            currentNode = newNode;
        }
        else
        {
            currentNode->next = newNode;
            currentNode = newNode;
        }
    }

    currentNode = head;

    while (currentNode != NULL)
    {
        cout << currentNode->data << " --> ";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;

    Node *newNode = new Node;
    newNode->data = 10;
    newNode->next = head;

    head = newNode;
    currentNode = head;

    while (currentNode != NULL)
    {
        cout << currentNode->data << " --> ";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
    return 0;
}