// Task 2 : Create one node dynamically, store a value in data, and set its next pointer to NULL.

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
    firstNode->data = 100;
    firstNode->next = NULL;

    cout << "FIrst Node DATA: " << firstNode->data << endl;

    delete firstNode;
}