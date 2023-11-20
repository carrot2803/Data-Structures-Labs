#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

int main() {
  
   Node * top;
   Node * copy;
   Node * newTop;
   Node * mergedList;

   cout << "Linked List Operations for Lab #2, Question 3" << endl;
   cout << "=============================================" << endl;
 
   cout << "\nNow about to insert 23, 5, 30, 45, 2 in ascending order ...\n";

   top = NULL; 						// no elements as yet so top must be NULL

   top = insertSortedRec (top, 23);
   top = insertSortedRec (top, 5);
   top = insertSortedRec (top, 30);
   top = insertSortedRec (top, 45);
   top = insertSortedRec (top, 2);
     
   cout << "\nThe linked list contains the following elements:\n";
   printList(top);
   
   cout << "\nNow about to copy this list ... " << endl;
   
   copy = copyListRec (top);

   cout << "\nThe copied linked list contains the following elements:\n";
   printList(copy);

   if (isEqualRec (top, copy))
   		cout << "\nBoth lists are equal." << endl;
   else
   		cout << "\nBoth lists are NOT equal." << endl;
   
   
   cout << "\nNow about to insert 200, 10, 25, 35, 175 in a new linked list (ascending order)." << endl;
   
   newTop = NULL;
   
   newTop = insertSortedRec (newTop, 200);
   newTop = insertSortedRec (newTop, 10);
   newTop = insertSortedRec (newTop, 25);
   newTop = insertSortedRec (newTop, 35);
   newTop = insertSortedRec (newTop, 175);
   
   cout << "\nThe new list contains the following elements: " << endl;
   printList (newTop);
   
   if (isEqualRec (top, newTop))
   		cout << "\nBoth lists are equal." << endl;
   else
   		cout << "\nBoth lists are NOT equal." << endl;
   
   cout << "\nNow about to merge lists." << endl;
   
   mergedList = mergeRec (top, newTop);
   
   cout << "\nThe merged list contains the following elements: " << endl;
   printList (mergedList);
   
   cout << "\n*** End of Linked List Operations ***" << endl;

   return 0;
}
