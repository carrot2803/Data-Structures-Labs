#include <cstring>
#include <iostream>

#include "MaxPriorityQueue.h"

using namespace std;

int main() {
    MaxPriorityQueue* maxPQ;
    int x;
    int A[10] = {10, 60, 5, 25, 70, 65, 45, 50, 15, 80};

    // code for (b) (i)
    maxPQ = initMaxPQ(A, 10);

    cout << "The priority queue contains the following elements:" << endl;
    displayMaxPQ(maxPQ);
    cout << endl;

    cout << "The biggest element in the priority queue is " << maximumPQ(maxPQ) << endl;

    // write code for (b) (ii)

    cout << endl;

    cout << "Inserting 75 in the priority queue ..." << endl;

    // write code for (b) (iii)

    cout << "The priority queue now contains the following elements:" << endl;
    displayMaxPQ(maxPQ);
    cout << endl;

    cout << "Removing the biggest element in priority queue: " << extractMaximumPQ(maxPQ) << endl;

    // write code for (b) (iv)

    cout << "The priority queue now contains the following elements:" << endl;
    displayMaxPQ(maxPQ);
    cout << endl;

    cout << "Increasing the priority of element 8 to 90: " << endl;

    // write code for (b) (v)

    cout << "The priority queue now contains the following elements:" << endl;
    displayMaxPQ(maxPQ);
    cout << endl;

    return 0;
}
