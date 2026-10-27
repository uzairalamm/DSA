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

    void deletionAtBegin()
    {
        if (head == nullptr)
        {
            cout << "Linked list is Empty\n";
            return;
        }

        Node *nodeToDelete = head;
        head = head->next;
        head->pre = nullptr;
        delete nodeToDelete;
        tail->next = head;
    }

    void deletionAtEnd()
    {
        if (head == nullptr)
        {
            cout << "Linked list is Empty\n";
            return;
        }

        Node *nodeToDelete = tail;
        tail = tail->pre;
        tail->next = nullptr;
        delete nodeToDelete;
        tail->next = head;
    }

    void deletionAtPosition(int pos)
    {
        if (pos < 1)
        {
            cout << "invalid Position\n";
            return;
        }

        if (pos == 1)
        {
            deletionAtBegin();
            return;
        }

        Node *current = head;
        Node *previous = nullptr;
        for (int i = 1; i < pos; i++)
        {
            previous = current;
            current = current->next;
            if (current == nullptr)
            {
                cout << "Invalid Position\n";
                return;
            }
        }

        previous->next = current->next;
        if (current != tail)
            current->next->pre = previous;
        if (current == tail)
            tail = previous;
        delete current;
        tail->next = head;
    }
    void traversal() const
    {
        Node *current = head;

        do
        {
            cout << current->id << " " << current->next;
            current = current->next;
        } while (current != head);
        cout << endl;
    }
    void traversalBackward() const
    {
        Node *current = tail;
        do
        {
            cout << current->id << " " << current->next;
            current = current->pre;
        } while (current != head);
        cout << current->id << endl;
    }
};

int main()
{
    doubleLinkList list;
    list.insertAtBegin("103");
    list.insertAtBegin("102");
    list.insertAtBegin("101");
    list.deletionAtPosition(3);
    cout << list.head << ' ' << list.tail << endl;
    list.traversal();
    list.traversalBackward();
}