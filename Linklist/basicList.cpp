#include <iostream>
using namespace std;

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

    // Print Node Data through Loop
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
}
