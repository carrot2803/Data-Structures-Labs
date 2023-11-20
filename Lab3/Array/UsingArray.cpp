#include <iostream>
#include <cstdlib>
#include "Array.h"

using namespace std;

int main() {
  
   	cout << "Array Operations for Lab #3, Question 1" << endl;
   	cout << "=======================================" << endl;
   
   	int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
   	
	int key;
	bool found;
	int sum, max;
	
	cout << "These are the elements in the array: " << endl;
	
	printArrayRec (a, 0, 10);
	cout << endl;

	cout << "\nPlease enter a value to search for: " << endl;
	cin >> key;
	
	found = containsArrayRec(a, 0, 10, key);
	
	cout << endl;
	
	if (found == true)
		cout << key << " found in array." << endl;	
	else 
		cout << key << " not found in array." << endl;
	
	sum = sumArrayRec (a, 0, 10);
	cout << "\nThe sum of the elements in the array is: " << sum << endl;

	max = maxArrayRec (a, 0, 10);
	cout << "\nThe maximum element in the array is: " << max << endl;	
	
	cout << "\nPlease enter a value to search for using binary search: " << endl;
	cin >> key;
	
	found = binarySearchRec(a, 0, 9, key);
	
	if (found == true)
		cout << key << " found in array." << endl;	
	else 
		cout << key << " not found in array." << endl;	

	cout << "\n*** End of Array Operations ***" << endl;    

	return 0;

}
