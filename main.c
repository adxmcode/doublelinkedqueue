#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

typedef SList Deque;


void push_back(Deque* taylor, char* data) {
    char* nameGetter = malloc(strlen(data) + 1);
    strcpy(nameGetter, data);
    insertTail(taylor, nameGetter);
}

void push_front(Deque* taylor, char* data) {
    char* nameGetter = malloc(strlen(data) + 1);
    strcpy(nameGetter, data);
    insertHead(taylor, nameGetter);
}

char* pop_front(Deque* taylor) {
   char* name = removeHead(taylor);
   return name;
}

char* pop_back(Deque* taylor) {
    char* name = removeTail(taylor);
    return name;
}

void loadDataFromFile(Deque* taylor, const char* filename) {
    FILE* file = fopen(filename, "r");
    if(!file)  {
        printf("Cannot open file\n");
        exit(1);
    } 
    
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';  
        if (strlen(buffer) > 0) {
            push_back(taylor, buffer);  
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]){
    const char* filename = NULL;
    
    if(argc == 2) {
        filename = argv[1];
    } else {
        filename = "names.txt";
    }

    Deque q = { NULL,  NULL };
    //Finish code here;
    loadDataFromFile(&q, filename);

    char command;
    printf("To scroll through the names type\nf: forwards, b: backwards, q: quit\n");
    
    while(1) {
        scanf(" %c", &command);

        if(command == 'q') {
            printf("Bye!\n");
            break;
        } 
        else if (command == 'f') {
            char* name = pop_front(&q);
            if (name) {
                printf("%s\n", name);
                push_back(&q, name);
            } else {
                printf("deque empty\n");
            }
        } 
        else if (command == 'b') {
            char* name = pop_back(&q);
            if (name) {
                printf("%s\n", name);
                push_front(&q, name);
            } else {
                printf("deque empty\n");
            }
        } 
        else {
            printf("invalid command. \n");
        }
    }
    return 0;
}