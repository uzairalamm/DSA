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
    Node *firstNode = new Node("O101");
    Node *secondNode = new Node("O102");
    Node *thirdNode = new Node("O103");
    Node *fourthNode = new Node("O104");

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

    // Inserting new Node at the end
    Node *fifthNode = new Node("O105");
    fifthNode->next = nullptr;
    current->next = fifthNode;

    // Inserting new Node after O102
    current = head;
    while (current->productID != "O102")
    {
        current = current->next;
    }

    Node *sixthNode = new Node("O1025");
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