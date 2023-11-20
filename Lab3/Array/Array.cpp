#include "Array.h"

#include <climits>
#include <cstdlib>
#include <iostream>

using namespace std;

// insert function definitions for Lab #3, Question 1

void printArrayRec(int a[], int start, int n) {
    if (start == n) return;
    cout << a[start] << " ";
    printArrayRec(a, start + 1, n);
}

bool containsArrayRec(int arr[], int start, int n, int key) {
    if (start == n)
        return false;
    else if (arr[start] == key)
        return true;
    return containsArrayRec(arr, start + 1, n, key);
}
// sorry i fed up start and a[]
int sumArrayRec(int arr[], int i, int n) {
    if (i == n) return 0;
    return arr[i] + sumArrayRec(arr, i + 1, n);
}

int maxArrayRec(int a[], int start, int n) {
    if (start >= n) return -1;
    if (start == n - 1) return start;
    int maxIndex = maxArrayRec(a, start + 1, n);
    return (a[start] > a[maxIndex]) ? start : maxIndex;
}

bool binarySearchRec(int a[], int start, int end, int key) {
    if (start > end) return false;
    int mid = (start + end) / 2;
    if (a[mid] == key)
        return true;
    else if (a[mid] > key)
        return binarySearchRec(a, start, mid - 1, key);
    return binarySearchRec(a, mid + 1, end, key);
}

// Alternative

// bool binarySearchRec(int arr[], int start, int end, int key) {
//     int mid = (start + end) / 2;
//     if (arr[mid] == key)
//         return true;
//     else if (arr[mid] > key)
//         return binarySearchRec(arr, start, mid - 1, key);
//     else
//         return binarySearchRec(arr, mid + 1, end, key);
//     return false;
// }
