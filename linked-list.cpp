// Linked list

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
	int data;
	Node * next;
};

Node * initNewNode(int data) {
	Node *node;
	node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void insert(Node **head, int data) {
	if(*head == NULL) {
		*head= initNewNode(data);	
	} else {
		Node *headTraverser = *head;
		while(headTraverser->next != NULL){
			headTraverser = headTraverser->next;
		}
		Node *newNode = initNewNode(data);
		headTraverser->next = newNode;
	}
}

void printList(Node *head) {
	while(head != NULL) {
		printf(" | %d | -> ", head->data);
		head = head->next;
	}
	printf("NULL");
}

int main() {
	Node *head=NULL;
	insert(&head, 10);
	insert(&head, 12);
	insert(&head, 18);
	insert(&head, 19);
	printList(head);
	return 0;
}
