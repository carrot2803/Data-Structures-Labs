#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// function prototypes

Node* createNode(int n);
void printList(Node* top);

// implementation of functions

Node* createNode(int n) {
    Node* newNode;

    newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    return newNode;
}

void printList(Node* top) {
    Node* curr;

    curr = top;
    while (curr != NULL) {
        cout << curr->data << "\t";
        curr = curr->next;
    }

    cout << "\n";
}

Node* deleteSecond(Node* top) {
    if (top == NULL || top->next == NULL) return NULL;
    Node* temp = top->next;
    top->next = top->next->next;
    delete temp;
    return top;
}

Node* addBeforeLast(Node* top, int n) {
    if (top == NULL || top->next == NULL) {
        Node* newNode = createNode(n);
        newNode->next = top;
        return newNode;
    }
    top->next = addBeforeLast(top->next, n);
    return top;
}

Node* deleteAtHead(Node* top) {
    if (top == NULL) return NULL;
    Node* newTop = top->next;
    delete top;
    return newTop;
}

int sum(Node* top) {
    if (top == NULL) return 0;
    return top->data + sum(top->next);
}

int main() {
    Node* top;
    Node* newNode;

    top = createNode(10);
    top->next = createNode(20);
    top->next->next = createNode(30);
    top->next->next->next = createNode(50);

    cout << "\na. Create a linked list with four nodes: ";
    printList(top);

    cout << "\nb. Delete the second node:\n";
    top = deleteSecond(top);
    printList(top);

    cout << "\nc. Add before last: \n";
    top = addBeforeLast(top, 40);
    printList(top);

    cout << "\nd. Delete the first node:\n";
    top = deleteAtHead(top);
    printList(top);

    cout << "\ne. Sum of list values:\n";
    cout << "Sum of elements in list is: " << sum(top) << endl;

    return 0;
}
