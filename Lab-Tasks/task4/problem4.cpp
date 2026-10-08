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
    Node *firstNode = new Node("E101");
    Node *secondNode = new Node("E102");
    Node *thirdNode = new Node("E103");
    Node *fourthNode = new Node("E104");

    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;
    fourthNode->next = nullptr;

    // Inserting new Node after E102
    head = firstNode;
    current = head;
    while (current->productID != "E102")
    {
        current = current->next;
    }

    Node *fifthNode = new Node("E1025");
    fifthNode->next = current->next;
    current->next = fifthNode;

    // Inserting new Node after E103
    current = head;
    while (current->productID != "E103")
    {
        current = current->next;
    }

    Node *sixthNode = new Node("E1035");
    sixthNode->next = current->next;
    current->next = sixthNode;

    current = head;
    while (current->next != nullptr)
    {
        cout << current->productID << " -> ";
        current = current->next;
    }
    cout << current->productID << " -> ";
    cout << "nullptr" << endl;
}