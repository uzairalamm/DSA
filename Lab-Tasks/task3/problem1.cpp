#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;

int main()
{
    Node *currentNode = NULL;

    for (int i = 1; i <= 10; i += 2)
    {
        Node *newNode = new Node;
        newNode->data = i * 10;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            currentNode = newNode;
        }
        else
        {
            currentNode->next = newNode;
            currentNode = newNode;
        }
    }

    int i = 1;
    currentNode = head;
    while (currentNode != NULL)
    {
        cout << "Node " << i << "\nData: " << currentNode->data << "\nAddress: " << currentNode->next << "\n"
             << endl;
        currentNode = currentNode->next;
        i++;
    }

    return 0;
}