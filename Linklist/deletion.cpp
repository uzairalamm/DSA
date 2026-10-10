#include <iostream>
#include <string>
using namespace std;

// Rigth Now, I just added a tail, so i donot have to traverse the whole list to insert a new node at the end
struct Node
{
    string productID;
    Node *next;

    Node() : productID(""), next(nullptr) {}
    Node(const string &id) : productID(id), next(nullptr) {}
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(const string &id)
    {
        Node *newNode = new Node(id);
        newNode->next = head;
        head = newNode;

        if (tail == nullptr)
            tail = newNode;
    }
    bool insertBefore(const string &targetID, const string &id)
    {
        Node *currentNode = head;
        Node *previousNode = nullptr;
        while (currentNode != nullptr && currentNode->productID != targetID)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        if (currentNode == nullptr)
            return false;

        if (previousNode == nullptr)
        {
            insertAtBeginning(id);
            return true;
        }

        Node *newNode = new Node(id);
        newNode->next = previousNode->next;
        previousNode->next = newNode;

        return true;
    }

    bool insertAfter(const string &targetID, const string &id)
    {
        Node *currentNode = head;
        while (currentNode != nullptr && currentNode->productID != targetID)
            currentNode = currentNode->next;

        if (currentNode == nullptr)
            return false;

        Node *newNode = new Node(id);
        newNode->next = currentNode->next;
        currentNode->next = newNode;

        if (tail == currentNode)
            tail = newNode;

        return true;
    }

    void insertAtEnd(const string &id)
    {
        Node *newNode = new Node(id);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void traversal() const
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->productID << " ";
            cout << currentNode->next << endl;
            currentNode = currentNode->next;
        }
    }

    ~LinkedList()
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            Node *temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;
    list.insertAtBeginning("O100");
    list.insertAtEnd("O101");
    list.insertAtEnd("O102");
    list.insertAtEnd("O103");
    list.traversal();

    list.insertAfter("O102", "O1025");
    list.insertBefore("O100", "O1000");
    list.traversal();

    return 0;
}