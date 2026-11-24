/*A browser stores visited page numbers in a stack. The visited pages are 101, 102, 103, 104.
Write a C++ program using a linked list to:
Push all page numbers into the stack.
Display the browser history.
Perform the Back operation using Pop.
Display the updated history.
Show the current page using Peek.*/


#include <iostream>
using namespace std;

class Node {
public:
    int pageNumber;
    Node* next;

    Node(int pageNumber) {
        this->pageNumber = pageNumber;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int pageNumber) {
        Node* newNode = new Node(pageNumber);

        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Back from page: " << top->pageNumber << endl;

        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == nullptr) {
            cout << "No current page!" << endl;
            return;
        }

        cout << "Current page: " << top->pageNumber << endl;
    }

    void display() {
        if (top == nullptr) {
            cout << "Browser history is empty!" << endl;
            return;
        }

        Node* currentNode = top;

        cout << "Browser History (Top to Bottom): ";

        while (currentNode != nullptr) {
            cout << currentNode->pageNumber << " ";
            currentNode = currentNode->next;
        }

        cout << endl;
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack browser;

    // Push all visited pages
    browser.push(101);
    browser.push(102);
    browser.push(103);
    browser.push(104);

    // Display browser history
    cout << "Initial Browser History:" << endl;
    browser.display();

    // Perform Back operation
    cout << "\nPerforming Back Operation:" << endl;
    browser.pop();

    // Display updated history
    cout << "\nUpdated Browser History:" << endl;
    browser.display();

    // Show current page
    cout << endl;
    browser.peek();

    return 0;
}
