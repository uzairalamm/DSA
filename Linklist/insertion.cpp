#include <iostream>
using namespace std;

struct Node
{
    int data{};
    Node *next;
};
Node *head = NULL;
Node *lastNode = NULL;

int main()
{
    // Creating Nodes
    Node *firstNode = new Node;
    Node *secondNode = new Node;
    Node *thirdNode = new Node;

    // Inserting Data
    firstNode->data = 10;
    secondNode->data = 20;
    thirdNode->data = 30;

    // Connecting Nodes
    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = NULL;

    // Also Pointing Head to the First Node
    head = firstNode;
    lastNode = thirdNode;

    // Print Node Data through Loop
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;

    // inserting Node at first
    Node *newNode = new Node;
    newNode->data = 5;
    newNode->next = head;

    head = newNode;
    currentNode = head;

    while (currentNode != NULL)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;

    // Inserting At Last (As a NOOB........Maybe)
    newNode = new Node;
    newNode->data = 40;
    newNode->next = NULL;
    lastNode->next = newNode;

    currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}