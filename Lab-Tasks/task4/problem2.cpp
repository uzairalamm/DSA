#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next;

    Node(const string &station) : data(station), next(nullptr) {}
};

Node *head = nullptr;
Node *current = nullptr;

int main()
{
    Node *firstNode = new Node("Lahore");
    Node *secondNode = new Node("Gujranwala");
    Node *thirdNode = new Node("Rawalpindi");
    Node *fourthNode = new Node("Islamabad ");

    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;
    fourthNode->next = nullptr;

    head = firstNode;
    current = head;
    while (current->data != "Gujranwala")
    {
        current = current->next;
    }

    Node *fifthNode = new Node("Gujrat");
    fifthNode->next = current->next;
    current->next = fifthNode;

    current = head;
    while (current->next != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << current->data;
}