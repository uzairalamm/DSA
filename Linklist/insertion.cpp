#include <iostream>
using namespace std;
// This code is like a basic understanding of how linked list works and how to insert nodes in a linked list
// struct Node
// {
//     int data{};
//     Node *next;
// };
// Node *head = NULL;

// int main()
// {
//     // Creating Nodes
//     Node *firstNode = new Node;
//     Node *secondNode = new Node;
//     Node *thirdNode = new Node;

//     // Assigning Data To Nodes
//     firstNode->data = 10;
//     secondNode->data = 20;
//     thirdNode->data = 30;

//     // Linking Nodes
//     firstNode->next = secondNode;
//     secondNode->next = thirdNode;
//     thirdNode->next = NULL;

//     // Pointing Head to First Node
//     head = firstNode;

//     // Print Node Data through Loop
//     Node *currentNode = head; // starting from head
//     while (currentNode != NULL)
//     {
//         cout << currentNode->data << " ";
//         currentNode = currentNode->next;
//     }
//     cout << endl;

//     // inserting Node at first
//     Node *newNode = new Node;
//     newNode->data = 5;
//     newNode->next = head;
//     head = newNode;

//     currentNode = head; // doing this so linked list can be printed from head(starting point)
//     while (currentNode->next != NULL)
//     {
//         cout << currentNode->data << " ";
//         currentNode = currentNode->next;
//     }
//     cout << currentNode->data;
//     cout << endl;

//     // Inserting At Last (As a NOOB........Maybe)
//     newNode = new Node;
//     newNode->data = 40;
//     newNode->next = NULL;
//     currentNode->next = newNode;

//     currentNode = head;
//     while (currentNode != NULL)
//     {
//         cout << currentNode->data << " ";
//         currentNode = currentNode->next;
//     }
//     cout << endl;

//     // Inserting anywhere in the List (As a NOOB........)
//     newNode = new Node;
//     newNode->data = 15; // gonna insert in after 10
//     currentNode = head; // start from head
//     while (currentNode->data != 10)
//     {
//         currentNode = currentNode->next;
//     }
//     newNode->next = currentNode->next;
//     currentNode->next = newNode;

//     currentNode = head;
//     while (currentNode != NULL)
//     {
//         cout << currentNode->data << " ";
//         currentNode = currentNode->next;
//     }

//     return 0;
// }

// -----------------------------------------------------------------------------------------------------------------
// Now Lets create a proper Linked list class....
// this is just a basic way to create a linked list class and insert nodes in it..
// struct Node
// {
//     string productID;
//     Node *next;
//     Node() : productID(""), next(nullptr) {}
//     Node(const string &id) : productID(id), next(nullptr) {}
// };

// class LinkedList
// {
//     Node *head;

// public:
//     LinkedList() : head(nullptr) {}

//     void insertAtBeginning(const string &id)
//     {
//         Node *newNode = new Node(id);
//         newNode->next = head;
//         head = newNode;
//     }

//     void insertAtEnd(const string &id)
//     {
//         Node *newNode = new Node(id);
//         if (head == nullptr)
//         {
//             head = newNode;
//             return;
//         }

//         Node *current = head;
//         while (current->next != nullptr)
//         {
//             current = current->next;
//         }
//         current->next = newNode;
//     }

//     void traversal()
//     {
//         Node *currentNode = head;
//         while (currentNode != nullptr)
//         {
//             cout << currentNode->productID << " ";
//             currentNode = currentNode->next;
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     LinkedList list;
//     list.insertAtEnd("O101");
//     list.insertAtEnd("O102");
//     list.traversal();
//     list.insertAtBeginning("O100");
//     list.traversal();
// }

// -----------------------------------------------------------------------------------------------------------------
// A better way is to create tail pointer in linked list class so we donot have to traverse the whole list again and again to insert at the end
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
        newNode->next = head; // nullptr if the list is empty, otherwise points to the current head
        head = newNode;
        if (tail == nullptr) // if the list is empty, set tail to the new node as well
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
        {
            currentNode = currentNode->next;
        }

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

        tail->next = newNode; // connect tail's next to the new node
        tail = newNode;       // update tail to point to the new node
    }

    void traversal()
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->productID << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.insertAtEnd("O101");
    list.insertAtEnd("O102");
    list.traversal();
    list.insertAtBeginning("O100");
    list.insertBefore("O101", "O1010");
    list.insertAfter("O101", "O1015");
    list.traversal();
}
