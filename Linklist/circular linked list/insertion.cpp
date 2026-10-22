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
        tail->next = head;
    }

    void insertAtPosition(const string &id, int pos)
    {
        if (pos < 1)
        {
            cout << "Please Enter Valid Position!\n";
            return;
        }

        if (pos == 1)
        {
            insertAtBegin(id);
            return;
        }

        Node *newNode = new Node(id);
        Node *current = head;
        for (int i = 1; i < pos - 1; i++)
        {
            if (current == nullptr)
                return;
            current = current->next;
        }

        newNode->next = current->next;
        newNode->pre = current;

        if (current != tail)
            current->next->pre = newNode;
        current->next = newNode;

        if (current == tail)
            tail = newNode;
        tail->next = head;
    }

    void insertAfterTarget(const string &target, const string &id)
    {
        Node *current = head;

        while (current != nullptr && current->id != target)
            current = current->next;

        if (current == nullptr)
        {
            cout << "Target Doesn't Exist\n";
            return;
        }

        Node *newNode = new Node(id);

        newNode->next = current->next;
        newNode->pre = current;

        if (current->next != nullptr)
            current->next->pre = newNode;

        current->next = newNode;

        if (current == tail)
            tail = newNode;
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

        do
        {
            cout << current->id << " ";
            current = current->pre;
        } while (current != head);
        cout << current->id << endl;
    }
};

int main()
{
    doubleLinkList list;
    list.insertAtBegin("102");
    list.insertAtBegin("101");
    list.insertionAtEnd("103");
    list.insertionAtEnd("105");
    list.insertAtPosition("106", 5);
    list.insertAfterTarget("106", "1006");

    cout << list.head << " " << list.tail->next << endl;
    list.traversal();
    list.traversalBackward();
}