#include <cstdlib>
#include <fstream>
#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
    cout << "Linked List Operations for Lab #2 Question 2" << endl;
    cout << "============================================" << endl;
    Node* top = NULL;
    // Write code to test recursive functions
    // insert 17, 23, and 250, and 45 a
    top = insertAtTail(top, 17);
    top = insertAtTail(top, 23);
    top = insertAtTail(top, 250);
    top = insertAtTail(top, 45);

    cout << "\nElements in the list: \n";
    printListRec(top);

    cout << "\nThe number of elements in the list are: " << sizeRec(top) << endl;

    cout << "\nThe sum of the elements in the list are: " << sumRec(top) << endl;

    int key;
    cout << "\nPlease enter a value to search for in the linked list: ";
    cin >> key;

    if (containsRec(top, key))
        cout << key << " was found in the list." << endl;
    else
        cout << key << " was not found in the list." << endl;

    cout << "\n*** End of Linked List Operations ***" << endl;

    return 0;
}
