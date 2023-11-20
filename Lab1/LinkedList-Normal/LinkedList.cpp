#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

// function prototypes

Node *createNode(int n);
Node *insertAtHead(Node *top, int n);
Node *insertAtTail(Node *top, int n);
Node *insertAtIndex(Node *top, int n, int index);
Node *deleteAtHead(Node *top);
Node *getIndex(Node *top, int index);
Node *getLast(Node *top);
bool contains(Node *top, int key);
int size(Node *top);
void printList(Node *top);

Node *createNode(int n) {
    Node *newNode;
    newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtHead(Node *top, int n) {
    Node *newNode;
    newNode = createNode(n);
    newNode->next = top;
    top = newNode;
    return top;  // return pointer to new head of list
}

Node *insertAtTail(Node *top, int n) {
    return (getLast(top) == NULL) ? createNode(n) : getLast(top)->next = createNode(n);
}

Node *insertAtIndex(Node *top, int n, int index) {
    int len;
    Node *curr;
    Node *newNode;
    Node *previous;
    len = size(top);
    if (index < 0 || index > len) return NULL;  // invalid index

    if (index == 0)
        return insertAtHead(top, n);  // insert at the top of the list
    else if (index == len)            // insert at the tail of the list
        return insertAtTail(top, n);
    else {  // insert somewhere inside the list
        newNode = createNode(n);
        curr = top;
        int i = 0;
        while (i < index) {
            previous = curr;
            curr = curr->next;
            i++;
        }
        newNode->next = previous->next;
        previous->next = newNode;
        return top;
    }
}

Node *deleteAtHead(Node *top) {
    Node *curr;

    curr = top;
    if (top == NULL)
        return NULL;
    else {
        curr = top;
        top = top->next;
        free(curr);
        return top;
    }
}

Node *getIndex(Node *top, int index) {
    int i, len;
    Node *curr;

    curr = top;
    len = size(top);

    if (index >= 0 && index < len) {
        for (i = 0; i < index; i++) curr = curr->next;
        return curr;
    } else
        return NULL;
}

Node *getLast(Node *top) { return (top) ? getLast(top->next) : top; }

bool contains(Node *top, int key) {
    while (top != NULL) {
        if (top->data == key) return true;
        top = top->next;
    }
    return false;
}

int size(Node *top) {
    Node *curr;
    int numNodes = 0;

    curr = top;
    while (curr != NULL) {
        numNodes = numNodes + 1;
        curr = curr->next;
    }
    return numNodes;
}

void printList(Node *top) {
    if (top != NULL) return;
    cout << top->data << endl;
    printList(top->next);
}

int main() {
    // Write code for Question 2.
    Node *top = NULL;
    top = insertAtHead(top, 17);
    top = insertAtHead(top, 23);
    top = insertAtHead(top, 250);
    printList(top);

    top = insertAtTail(top, 4);
    top = insertAtTail(top, 10);
    top = insertAtTail(top, 500);
    top = insertAtTail(top, 25);
    printList(top);

    Node *third = getIndex(top, 3 - 1);
    Node *tenth = getIndex(top, 10 - 1);

    if (third != NULL)
        cout << "Third element (index 2): " << third->data << endl;
    else
        cout << "Element at index 2 does not exist." << endl;

    if (tenth != NULL)
        cout << "Tenth element (index 9): " << tenth->data << endl;
    else
        cout << "Element at index 9 does not exist." << endl;

    Node *last = getLast(top);
    cout << "Last Element is: " << last->data << endl;

    int element[] = {25, 250, 18};
    for (int i = 0; i < 3; i++) cout << boolalpha << contains(top, element[i]) << "\t" << element[i] << endl;

    cout << size(top) << endl;

    return 0;
}
