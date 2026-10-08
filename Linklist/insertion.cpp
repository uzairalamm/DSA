#include <iostream>
using namespace std;
// This code is like a basic understanding of how linked list works and how to insert nodes in a linked list
struct Node
{
    int data{};
    Node *next;
};
Node *head = NULL;

int main()
{
    // Creating Nodes
    Node *firstNode = new Node;
    Node *secondNode = new Node;
    Node *thirdNode = new Node;

    // Assigning Data To Nodes
    firstNode->data = 10;
    secondNode->data = 20;
    thirdNode->data = 30;

    // Linking Nodes
    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = NULL;

    // Pointing Head to First Node
    head = firstNode;

    // Print Node Data through Loop
    Node *currentNode = head; // starting from head
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

    currentNode = head; // doing this so linked list can be printed from head(starting point)
    while (currentNode->next != NULL)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << currentNode->data;
    cout << endl;

    // Inserting At Last (As a NOOB........Maybe)
    newNode = new Node;
    newNode->data = 40;
    newNode->next = NULL;
    currentNode->next = newNode;

    currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;

    // Inserting anywhere in the List (As a NOOB........)
    newNode = new Node;
    newNode->data = 15; // gonna insert in after 10
    currentNode = head; // start from head
    while (currentNode->data != 10)
    {
        currentNode = currentNode->next;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;

    currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }

    return 0;
}