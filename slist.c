#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

//Helper method used for the included methods
Node* createNode(char* data) {
	Node* newNode = (struct node*)malloc(sizeof(struct node));

	if(!newNode) {
		exit(1);
	}
	newNode->data = malloc(strlen(data) + 1);
	if(!newNode->data) {
		exit(1);
	}
	strcpy(newNode->data, data);
	newNode->next = NULL;
	return newNode;
}


//Included methods
void insertHead(SList* list, char* data) {
	Node* newNode = createNode(data);
	newNode->next = list->head;
	list->head = newNode;

	if (list->tail == NULL) {
		list->tail = newNode;
	}
}

void insertTail(SList* list, char* data) {
	//insert at bottom;
	Node* newNode = createNode(data);

	if (list->tail == NULL) {
		list->head = newNode;
		list->tail = newNode;
	}
	else{
		list->tail->next = newNode;
		list->tail = newNode;
	}
}

char* removeHead(struct slist* list) {
	//remove the top;
	if (list->head == NULL) {
		return NULL;
	}

	Node* temp = list->head;
	char* data = temp->data;
	list->head = list->head->next;
	
	if (list->head == NULL) {
		list->tail = NULL;
	}
	
	free(temp);
	return data;
}

char* removeTail(struct slist * list) {
	//remove the bottom;
	if (list->head == NULL) {
	  return NULL;
	}

	if (list->head == list->tail) {
		char* data = list->tail->data;
		free(list->tail);
		list->head = NULL;
		list->tail = NULL;
		return data;
	}

	//trarversing from head to second last (n - 1);
	Node* current = list->head;
	
	while (current->next != list->tail) {
		current = current->next;
	}

	char* data = list->tail->data;
	free(list->tail);
	current->next = NULL;
	list->tail = current;
	return data;
}
