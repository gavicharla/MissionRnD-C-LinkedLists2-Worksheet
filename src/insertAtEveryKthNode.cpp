/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};


struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL)
		return NULL;

	struct node * temp = head;
	struct  node * hello = (struct node *)malloc(sizeof(struct node));
	hello->num = K;
	hello->next = NULL;
	int count = 0;
	while (temp != NULL)
	{
		if (count == K - 1)
		{
			struct node * new1 = (struct node *)malloc(sizeof(struct node));
			new1->num = K;
			new1->next = temp->next;
			temp->next = new1;
			count = 0;
			temp = temp->next;
		}
		else
			count++;
		if (temp != NULL)
			temp = temp->next;
	}
	return head;
}
