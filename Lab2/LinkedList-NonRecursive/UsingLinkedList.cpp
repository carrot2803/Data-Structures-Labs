#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
    Node* top;
    Node* copy;
    Node* newTop;
    Node* mergedList;

    cout << "Linked List Operations for Lab #2, Question 1" << endl;
    cout << "=============================================" << endl;

    cout << "\nNow about to insert 23, 5, 30, 45, 2 in sorted order ...\n";

    top = NULL;  // no elements as yet so top must be NULL

    top = insertSorted(top, 23);
    top = insertSorted(top, 5);
    top = insertSorted(top, 30);
    top = insertSorted(top, 45);
    top = insertSorted(top, 2);

    cout << "\nThe linked list now contains the following elements:\n";
    printList(top);

    cout << "\nNow about to copy this list ... " << endl;

    copy = copyList(top);

    cout << "\nThe copied linked list now contains the following elements:\n";
    printList(copy);

    if (isEqual(top, copy))
        cout << "Both lists are equal." << endl;
    else
        cout << "Both lists are NOT equal." << endl;

    cout << "Now about to insert 200, 10, 25, 35, 175 in a new linked list (sorted)." << endl;

    newTop = NULL;

    newTop = insertSorted(newTop, 200);
    newTop = insertSorted(newTop, 10);
    newTop = insertSorted(newTop, 25);
    newTop = insertSorted(newTop, 35);
    newTop = insertSorted(newTop, 175);

    cout << "The new list contains the following elements: " << endl;
    printList(newTop);

    if (isEqual(top, newTop))
        cout << "Both lists are equal." << endl;
    else
        cout << "Both lists are NOT equal." << endl;

    cout << "Now about to merge lists." << endl;

    mergedList = merge(top, newTop);

    cout << "The merged list contains the following elements: " << endl;
    printList(mergedList);

    cout << "Deleting the elements from the first list ..." << endl;
    clear(top);

    cout << "\nThe copied linked list now contains the following elements:\n";
    printList(copy);

    cout << "\n*** End of Linked List Operations ***" << endl;

    return 0;
}
