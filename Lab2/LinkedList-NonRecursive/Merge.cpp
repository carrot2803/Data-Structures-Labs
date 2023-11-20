//	This function merges the two linked lists passed as parameters. It is
//	assumed that the two linked lists are sorted in ascending order. No new
//	nodes are created. The funnction returns the top of the merged list.

Node * merge (Node * top1, Node * top2) {

	Node * newTop;						// top of the merged list
	Node * curr;
	
	if (top1 == NULL)					// first list is empty: return second list
		return top2;
		
	if (top2 == NULL)					// second list is empty: return first list
		return top1;	
	
	if (top1->data <= top2->data) {		// set top of merged list to either the head of the
		newTop = top1;					//   first list or the head of the second list
		top1 = top1->next;				//   (depending on which is smaller)
	}
	else {
		newTop = top2;
		top2 = top2->next;
	}
		
	curr = newTop;
	
	while (top1 != NULL && top2 != NULL) {	
										// keep going until one of the lists becomes empty
		if (top1->data <= top2->data) {	// attach node from first list, if smaller
			curr->next = top1;
			curr = curr->next;
			top1 = top1->next;
		}
		else {							// attach node from second list, if smaller
			curr->next = top2;
			curr = curr->next;
			top2 = top2->next;
		}
	}									// when loop is exited, either one or both lists
										//   are empty
										
	if (top1 != NULL)					// second list is empty: connect to the remaining
		curr->next = top1;				//   elements in the first list.
		
	if (top2 != NULL)					// first list is empty: connect to the remaining
		curr->next = top2;				//   elements in the second list.
		
	return newTop;						// return the top of the merged list
}
