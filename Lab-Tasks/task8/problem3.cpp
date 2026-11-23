#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SinglyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    SinglyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        if (tail == NULL)
        {
            tail = newNode;
        }
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int search(int key)
    {
        Node *current = head;
        int position = 1;
        while (current != NULL)
        {
            if (current->data == key)
            {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    void display()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data;
            if (current->next != NULL)
            {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void deleteFirst()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        delete temp;
    }

    void deleteLast()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = NULL;
    }

    void deleteValue(int key)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == key)
        {
            deleteFirst();
            return;
        }
        Node *current = head;
        while (current->next != NULL && current->next->data != key)
        {
            current = current->next;
        }
        if (current->next == NULL)
        {
            cout << "Value " << key << " not found" << endl;
            return;
        }
        Node *temp = current->next;
        current->next = temp->next;
        if (temp == tail)
        {
            tail = current;
        }
        delete temp;
    }
};