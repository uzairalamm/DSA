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
public:
    Node *head, *tail;

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
        tail->next = head;
    }

    void traversal() const
    {
        Node *current = head;
        do
        {
            cout << current->id << " ";
            current = current->next;
        } while (current != head);
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
    list.insertAtBegin("102");
    list.insertAtBegin("101");
    list.insertAtBegin("100");
    list.traversal();
    list.traversalBackward();
}