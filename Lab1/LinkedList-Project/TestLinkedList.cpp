#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
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