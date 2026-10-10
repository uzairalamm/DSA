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
    bool insertAfter(const string &targetID, const string &id)
    {
        Node *current = head;
        while (current != nullptr && current->productID != targetID)
            current = current->next;

        if (current == nullptr)
            return false;

        Node *newNode = new Node(id);
        newNode->next = current->next;
        current->next = newNode;

        if (tail == current)
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
            currentNode = currentNode->next;
        }
        cout << endl;
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
    list.insertAtEnd("O101");
    list.insertAtEnd("O102");
    list.insertAtEnd("O103");
    list.traversal();
    list.insertAtBeginning("O100");
    list.insertAfter("O102", "O1025");
    list.traversal();

    return 0;
}