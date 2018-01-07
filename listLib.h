#ifndef LISTLIB_H_
#define LISTLIB_H_

#include<stdio.h>
#include<stdlib.h>

typedef struct node_s{
    void *value;
    int type;
    struct node_s *next;
    struct node_s *prev;
}node_t;

typedef struct list_s{
    int cnt;
    node_t *head;
    node_t *tail;
}list_t;

typedef enum{
    CHAR,
    INT,
    LONG,
    U_INT,
    U_LONG,
    FLOAT,
    DOUBLE,
    LONG_DOUBLE
}type;

void *typeAlloc(type Type);
    
void putValue(type Type, void *a, node_t *Node);
    
void printValue(node_t Node);
    
void init(list_t *list);
    
void pushFront(type Type, void *a, list_t *list);
    
void pushBack(type Type, void *a, list_t *list);
    
void pushToPlace(int n, type Type, void *a, list_t *list);
    
void popFront(list_t *list);
    
void popBack(list_t *list);
    
void popFromPlace(int n, list_t *list);

void printTailToHead(list_t list);
    
void printHeadToTail(list_t list);
    
void printHead(list_t list);

void printTail(list_t list);
    
int isEmpty(list_t list);
    
void empty(list_t *list);

#endif
