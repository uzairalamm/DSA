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
    void insertBefore(const string &targetID, const string &id)
    {
        Node *currentNode = head;
        Node *previousNode = nullptr;
        while (currentNode != nullptr && currentNode->productID != targetID)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        if (currentNode == nullptr)
            return;

        if (previousNode == nullptr)
        {
            insertAtBeginning(id);
            return;
        }

        Node *newNode = new Node(id);
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }

    void insertAfter(const string &targetID, const string &id)
    {
        Node *currentNode = head;
        while (currentNode != nullptr && currentNode->productID != targetID)
            currentNode = currentNode->next;

        if (currentNode == nullptr)
        {
            cout << "Invalid Target!\n";
            return;
        }

        Node *newNode = new Node(id);
        newNode->next = currentNode->next;
        currentNode->next = newNode;

        if (tail == currentNode)
            tail = newNode;
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

    void insertAtPosition(const string &id, int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid Position\n";
            return;
        }
        if (pos == 1)
        {
            insertAtBeginning(id);
            return;
        }

        Node *newNode = new Node(id);
        Node *currentNode = head;

        for (int i = 1; i < pos - 1; i++)
        {
            currentNode = currentNode->next;
            if (currentNode == nullptr)
            {
                cout << "Invalid Position\n";
                return;
            }
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;

        if (tail == currentNode)
            tail = newNode;
    }

    // Deletion Methods

    void utilityForDeletion()
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    void deleteAtBeginning()
    {
        if (head == nullptr)
        {
            cout << "Linked list is already Empty!\n";
            return;
        }

        if (head == tail) // this mean linked list only have one node.
        {
            utilityForDeletion();
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "Linked list is already Empty!\n";
            return;
        }

        if (head == tail)
        {
            utilityForDeletion();
            return;
        }
        Node *current = head;

        while (current->next != tail)
            current = current->next;

        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    void deleteAtAnyPosition(int pos)
    {
        if (head == nullptr)
        {
            cout << "Linked list is already Empty!\n";
            return;
        }

        if (pos < 1)
        {
            cout << "Invalid Position\n";
            return;
        }
        if (pos == 1)
        {
            deleteAtBeginning();
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

        if (current == tail)
            tail = previous;

        previous->next = current->next;
        delete current;
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
    list.insertAfter("O102", "O1025");
    list.insertBefore("O100", "O1000");
    list.insertAtPosition("106", 5);
    list.deleteAtEnd();
    list.deleteAtAnyPosition(6);
    list.traversal();

    return 0;
}