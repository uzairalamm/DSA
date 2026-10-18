#include <iostream>
using namespace std;

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

    // Searching
    void contain(const string &target)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->productID == target)
            {
                cout << target << " exist in linked List!\n";
                return;
            }
            current = current->next;
        }
        cout << target << " doesn't Exist!\n";
    }

    int countNodes()
    {
        int count = 0;
        Node *current = head;

        while (current != nullptr)
        {
            current = current->next;
            count++;
        }
        return count;
    }

    int findPosition(const string &target)
    {
        int count = 1;
        Node *current = head;

        while (current != nullptr)
        {
            if (current->productID == target)
                return count;
            current = current->next;
            count++;
        }
        return -1;
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
    list.insertAtBeginning("O100");
    list.insertAtPosition("102", 2);
    list.insertAtPosition("103", 3);
    list.insertAtPosition("104", 4);
    list.traversal();

    string target;
    int totalNodes = list.countNodes();
    cout << "Enter the Target Product: ";
    cin >> target;

    system("cls");
    list.contain(target);
    cout << "Total Nodes in Linked List: " << totalNodes << endl;

    int pos = list.findPosition(target);
    if (pos == -1)
        cout << "Not Found\n";
    else
        cout << target << " At position " << pos << endl;
}
