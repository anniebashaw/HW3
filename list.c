#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	if (new_element->index <= head->index) {    // check if we need to insert new_element at front of list
		new_element->next = head;
		head = new_element;
	}
	else {
		list_t* temp = head;
		while(temp->next != NULL && new_element->index > temp->next->index) {   // increment temp until we find place to insert
			temp = temp->next;
		}
		new_element->next = temp->next;     // insert new_element
		temp->next = new_element;
	}
	
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

  // Initial declarations avoid unnecesarry end-checking
	list_t* temp1 = NULL;
	list_t* temp2 = head;
	list_t* temp3;
	while (temp2 != NULL) {       // Reverse next pointers; increment each temp value
		temp3 = temp2->next;
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;
	}
	
	head = temp1;                 // temp1 will land on last value

	return head;
}
