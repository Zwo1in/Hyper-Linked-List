#include<stdio.h>
#include<stdlib.h>

typedef struct node_s{
    float value;
    struct node_s *next;
    struct node_s *prev;
}node_t;

typedef struct list_s{
    int cnt;
    node_t *head;
    node_t *tail;
}list_t;

void init(list_t *list){
    list->cnt=0;
    list->head=NULL;
    list->tail=NULL;
}

void pushFront(float a, list_t *list){
    if(list->cnt==0){
        list->head=(node_t*)malloc(sizeof(node_t));
        list->head->value=a;
        list->head->next=NULL;
        list->head->prev=NULL;
        list->tail=list->head;
        (list->cnt)++;
    }else if(list->cnt==1){
        list->head=(node_t*)malloc(sizeof(node_t));
        list->head->value=a;            
        list->head->next=NULL;
        list->head->prev=list->tail;
        list->tail->next=list->head;
        (list->cnt)++;
    }else{
        node_t *tmp;
        tmp=list->head;
        list->head=(node_t*)malloc(sizeof(node_t));
        tmp->next=list->head;
        list->head->value=a;
        list->head->next=NULL;
        list->head->prev=tmp;
        (list->cnt)++;
    }
}

void pushBack(float a, list_t *list){
        if(list->cnt==0){
        (list->cnt)++;
        list->tail=(node_t*)malloc(sizeof(node_t));
        list->tail->value=a;
        list->tail->next=NULL;
        list->tail->prev=NULL;
        list->head=list->tail;
    }else if(list->cnt==1){
        list->tail=(node_t*)malloc(sizeof(node_t));
        list->tail->value=a;
        list->tail->next=list->head;
        list->tail->prev=NULL;
        list->head->prev=list->tail;
        (list->cnt)++;
    }else{
        node_t *tmp;
        tmp=list->tail;
        list->tail=(node_t*)malloc(sizeof(node_t));
        tmp->prev=list->tail;
        list->tail->value=a;
        list->tail->next=tmp;
        list->tail->prev=NULL;
        (list->cnt)++;
    }
}

void pushToPlace(int n, float a, list_t *list){
    if(n>list->cnt+1) printf("list to short\n");
    else if((n==0)||(n==list->cnt+1)) (n==0)? pushBack(a, list) : pushFront(a, list);
    else{
        node_t *tmp, *new;
        new=(node_t*)malloc(sizeof(node_t));
        if(list->cnt/2<n){
            tmp=list->head;
            for(int i=list->cnt; i>n; i--)
                tmp=tmp->prev;
        }else{
            tmp=list->tail;
            new=(node_t*)malloc(sizeof(node_t));
            for(int i=1; i<n; i++)
                tmp=tmp->next;  
        }
        new->next=tmp;
        new->prev=tmp->prev;
        new->value=a;
        tmp->prev=tmp->prev->next=new;   
        (list->cnt)++;
    }
}

void popFront(list_t *list){
    if(list->cnt==0)
        printf("List empty\n");
    else{
        printf("%f\n", list->head->value);
        node_t *tmp;
        tmp=list->head;
        free(list->head);
        list->head=(node_t*)malloc(sizeof(node_t));
        list->head=tmp->prev;
        (list->cnt)--;
    }
}

void popBack(list_t *list){
    if(list->cnt==0)
        printf("List empty\n");
    else{
        printf("%f\n", list->tail->value);
        node_t *tmp;
        tmp=list->tail;
        free(list->tail);
        list->tail=(node_t*)malloc(sizeof(node_t));
        list->tail=tmp->prev;
        (list->cnt)--;
    }
}

void popFromPlace(int n, list_t *list){
    if(n>list->cnt) printf("list too short");
    else if((n==1)||(n==list->cnt)) (n==1)? popBack(list) : popFront(list);
    else{
        node_t *tmp;
        if(list->cnt/2<n){
            tmp=list->head;
            for(int i=list->cnt; i>n; i--)
                tmp=tmp->prev;
        }else{
            tmp=list->tail;
            for(int i=1; i<n; i++)
                tmp=tmp->next;  
        }
        tmp->prev->next=tmp->next;
        tmp->next->prev=tmp->prev;
        printf("%f\n", tmp->value);
        free(tmp);
        (list->cnt)--;
    }
}
    
void printTailToHead(list_t *list){
    if(list->cnt==0) printf("List empty\n");
    else{
        node_t *tmp;
        tmp=list->tail;
        while(tmp!=NULL){
            printf("%f\n", tmp->value);
            tmp=tmp->next;
        }
    }
}

void printHeadToTail(list_t *list){
    if(list->cnt==0) printf("List empty\n");
    else{
        node_t *tmp;
        tmp=list->head;
        while(tmp!=NULL){
            printf("%f\n", tmp->value);
            tmp=tmp->prev;
        }
    }
}

void printHead(list_t *list){
    if(list->cnt==0) printf("List empty\n");
    else printf("%f\n", list->head->value);
}

void printTail(list_t *list){
    if(list->cnt==0) printf("List empty\n");
    else printf("%f\n", list->tail->value);
}

int isEmpty(list_t list){
    if(list.cnt==0) return 1;
    else return 0;
}

void empty(list_t *list){
    node_t *tmp;
    while(list->cnt!=0){
        tmp=list->head;
        free(list->head);
        list->head=tmp->prev;
        (list->cnt)--;
    }
    printf("list empty\n");
}
