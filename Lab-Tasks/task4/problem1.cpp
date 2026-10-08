#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string productID;
    Node *next;

    Node(const string &id) : productID(id), next(nullptr) {}
};

Node *head = nullptr;
Node *current = nullptr;

int main()
{
    Node *firstNode = new Node("p101");
    Node *secondNode = new Node("p102");
    Node *thirdNode = new Node("p103");
    Node *fourthNode = new Node("p104");

    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;
    fourthNode->next = nullptr;

    head = firstNode;
    current = head;
    while (current->next != nullptr)
    {
        cout << current->productID << " -> ";
        current = current->next;
    }
    cout << current->productID << " -> ";
    cout << "nullptr" << endl;

    Node *fifthNode = new Node("p105");
    fifthNode->next = nullptr;
    current->next = fifthNode;

    current = head;
    while (current->next != nullptr)
    {
        cout << current->productID << " -> ";
        current = current->next;
    }
    cout << current->productID << " -> ";
    cout << "nullptr" << endl;
}