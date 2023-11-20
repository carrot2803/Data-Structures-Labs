#include <iostream>
using namespace std;

struct LLNode {
    int data;
    LLNode* next;
};

struct Set {
    LLNode* top;
};

Set* initSet() {
    Set* s = new Set;
    s->top = NULL;
    return s;
}

LLNode* createNode(int n) {
    LLNode* newNode = new LLNode;
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

LLNode* insertAtHead(LLNode* top, int n) {
    if (top == NULL) return createNode(n);
    LLNode* newNode = createNode(n);
    newNode->next = top;
    top = newNode;
    return top;
}

LLNode* deleteNode(LLNode* top, int n) {
    if (top == NULL)
        return NULL;
    else if (top->data == n) {
        LLNode* temp = top->next;
        free(top);
        return temp;
    }
    top->next = deleteNode(top->next, n);
    return top;
}

bool contains(LLNode* top, int key) {
    if (top == NULL)
        return false;
    else if (top->data == key)
        return true;
    return contains(top->next, key);
}

bool isEmptySet(Set* s) {
    return s->top == NULL;
}

void insert(Set* s, int n) {
    s->top = insertAtHead(s->top, n);
}

bool setContains(Set* s, int key) {
    if (isEmptySet(s)) {
        cout << "Set is empty\n";
        return false;
    }
    return contains(s->top, key);
}

int deleteFromSet(Set* s, int key) {
    if (isEmptySet(s)) {
        cout << "Set is empty\n";
        return -1;
    }
    s->top = deleteNode(s->top, key);
    return key;
}

LLNode* unionLL(LLNode* top1, LLNode* top2) {
    LLNode* unionList = NULL;
    while (top1 != NULL) {
        if (!contains(unionList, top1->data))
            unionList = insertAtHead(unionList, top1->data);
        top1 = top1->next;
    }
    while (top2 != NULL) {
        if (!contains(unionList, top2->data))
            unionList = insertAtHead(unionList, top2->data);
        top2 = top2->next;
    }
    return unionList;
}

// m*n solution
LLNode* intersectLL(LLNode* top1, LLNode* top2) {
    LLNode* intersectList = NULL;
    while (top1 != NULL) {
        if (contains(top2, top1->data) && !contains(intersectList, top1->data))
            intersectList = insertAtHead(intersectList, top1->data);
        top1 = top1->next;
    }
    return intersectList;
}

Set* intersect(Set* s1, Set* s2) {
    Set* intersectSet = initSet();
    intersectSet->top = intersectLL(s1->top, s2->top);
    return intersectSet;
}

Set* unionSet(Set* s1, Set* s2) {
    Set* unionSet = initSet();
    unionSet->top = unionLL(s1->top, s2->top);
    return unionSet;
}

// Function to print elements of a linked list
void printList(LLNode* top) {
    if (top == NULL) return;
    cout << top->data << " ";
    printList(top->next);
}

int main() {
    Set *set1 = initSet(), *set2 = initSet();

    insert(set1, 1);
    insert(set1, 2);
    insert(set1, 3);

    insert(set2, 2);
    insert(set2, 3);
    insert(set2, 4);

    cout << "Set 1: ";
    printList(set1->top);

    cout << "\nSet 2: ";
    printList(set2->top);

    Set* intersection = intersect(set1, set2);
    cout << "\nIntersection: ";
    printList(intersection->top);

    Set* unionSetResult = unionSet(set1, set2);
    cout << "\nUnion: ";
    printList(unionSetResult->top);

    return 0;
}
