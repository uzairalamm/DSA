// Task 3 : Create three nodes containing 10, 20, and 30. Connect them in sequence and make the last node point to NULL.
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

    firstNode->data = 10;
    secondNode->data = 20;
    thirdNode->data = 30;

    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = NULL;

    cout << "FIrst Node DATA: " << firstNode->data << endl;
    cout << "Second Node DATA: " << secondNode->data << endl;
    cout << "Third Node DATA: " << thirdNode->data << endl;

    delete firstNode;
    delete secondNode;
    delete thirdNode;
}