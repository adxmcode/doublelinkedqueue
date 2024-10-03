#ifndef slist_h
#define slist_h

typedef struct node {
  char* data;
  struct node* next;
} Node;

typedef struct slist {
  Node* head;
  Node* tail;
} SList;

typedef struct singlylinkedlist Slist;

void insertHead(SList* list, char* data);
void insertTail(SList* list, char* data);
char* removeHead(SList* list);
char* removeTail(SList* list);

#endif