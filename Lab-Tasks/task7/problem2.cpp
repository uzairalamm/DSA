#include <iostream>
using namespace std;

struct Node
{
    string id;
    Node *next;
    Node *pre;

    Node() : id(""), next(nullptr), pre(nullptr) {}
    Node(const string &id) : id(id), next(nullptr), pre(nullptr) {}
};

class doubleLinkList
{
    Node *head, *tail;

public:
    doubleLinkList() : head(nullptr), tail(nullptr) {}

    void insertAtBegin(const string &id)
    {
        Node *newNode = new Node(id);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->pre = newNode;
        head = newNode;
    }

    void insertionAtEnd(const string &id)
    {
        Node *newNode = new Node(id);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->pre = tail;
        tail = newNode;
    }

    void traversal() const
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->id << " ";
            current = current->next;
        }
        cout << endl;
    }
    void traversalBackward() const
    {
        Node *current = tail;
        while (current != nullptr)
        {
            cout << current->id << " ";
            current = current->pre;
        }
        cout << endl;
    }
};

int main()
{
    doubleLinkList list;
    list.insertAtBegin("504");
    list.insertAtBegin("503");
    list.insertAtBegin("502");
    list.insertAtBegin("501");
    list.insertionAtEnd("505");
    list.traversal();
    list.traversalBackward();
}