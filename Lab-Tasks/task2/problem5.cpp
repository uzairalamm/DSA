// Task 5 : Create two nodes representing customers 101 and 102. Connect the first customer to the second using the next pointer.
#include <iostream>
using namespace std;

struct Node
{
    int data{};
    Node *next;
};

int main()
{
    Node *customer101 = new Node;
    Node *customer102 = new Node;
    customer101->data = 101;
    customer102->data = 102;

    customer101->next = customer102;
    customer102->next = NULL;

    cout << "Customer: " << customer101->data << endl;
    cout << "Customer: " << customer102->data << endl;

    delete customer101;
    delete customer102;
}