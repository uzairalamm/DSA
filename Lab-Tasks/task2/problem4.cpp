// Task 4 : Create three connected nodes and use a head pointer to point to the first node.Display the value stored in the first node.
#include <iostream>
using namespace std;

struct Node
{
    int data{};
    Node *next;
};

int main()
{

    Node *firstNode = new Node;
    Node *secondNode = new Node;
    Node *thirdNode = new Node;
    Node *Head = firstNode;

    firstNode->data = 10;
    secondNode->data = 20;
    thirdNode->data = 30;

    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = NULL;

    cout << "FIrst Node DATA: " << Head->data << endl;

    delete firstNode;
    delete secondNode;
    delete thirdNode;
}