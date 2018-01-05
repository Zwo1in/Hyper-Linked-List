#include"listLib.h"

void *typeAlloc(type Type){
    switch(Type){
        case 0: return malloc(sizeof(char)); break;
        case 1: return malloc(sizeof(int)); break;
        case 2: return malloc(sizeof(long)); break;
        case 3: return malloc(sizeof(unsigned int)); break;
        case 4: return malloc(sizeof(unsigned long)); break;
        case 5: return malloc(sizeof(float)); break;
        case 6: return malloc(sizeof(double)); break;
        case 7: return malloc(sizeof(long double)); break;
    }
    return NULL;
}

void getValue(type Type, void *a, node_t *Node){
    Node->type=Type;
    Node->value=typeAlloc(Node->type);
    Node->value=a;
}
  
void printValue(node_t Node){
    switch(Node.type){
        case 0: printf("%c\n", *(char*)Node.value); break;
        case 1: printf("%d\n", *(int*)Node.value); break;
        case 2: printf("%ld\n", *(long*)Node.value); break;
        case 3: printf("%du\n", *(unsigned int*)Node.value); break;
        case 4: printf("%lu\n", *(unsigned long*)Node.value); break;
        case 5: printf("%f\n", *(float*)Node.value); break;
        case 6: printf("%f\n", *(double*)Node.value); break;
        case 7: printf("%Lf\n", *(long double*)Node.value); break;
    }
    return NULL;
}

void init(list_t *list){
    list->cnt=0;
    list->head=NULL;
    list->tail=NULL;
}

void pushFront(type Type, void *a, list_t *list){
    if(list->cnt==0){
        list->head=(node_t*)malloc(sizeof(node_t));
        getValue(Type, a, list->head);
        list->head->next=NULL;
        list->head->prev=NULL;
        list->tail=list->head;
        (list->cnt)++;
        
    }else if(list->cnt==1){
        list->head=(node_t*)malloc(sizeof(node_t));
        getValue(Type, a, list->head);         
        list->head->next=NULL;
        list->head->prev=list->tail;
        list->tail->next=list->head;
        (list->cnt)++;
    }else{
        node_t *tmp;
        tmp=list->head;
        list->head=(node_t*)malloc(sizeof(node_t));
        tmp->next=list->head;
        getValue(Type, a, list->head);
        list->head->next=NULL;
        list->head->prev=tmp;
        (list->cnt)++;
    }
}

void pushBack(type Type, void *a, list_t *list){
    if(list->cnt==0){
        (list->cnt)++;
        list->tail=(node_t*)malloc(sizeof(node_t));
        getValue(Type, a, list->tail);
        list->tail->next=NULL;
        list->tail->prev=NULL;
        list->head=list->tail;
    }
    else if(list->cnt==1){
        list->tail=(node_t*)malloc(sizeof(node_t));
        getValue(Type, a, list->tail);
        list->tail->next=list->head;
        list->tail->prev=NULL;
        list->head->prev=list->tail;
        (list->cnt)++;
    }else{
        node_t *tmp;
        tmp=list->tail;
        list->tail=(node_t*)malloc(sizeof(node_t));
        tmp->prev=list->tail;
        getValue(Type, a, list->tail);
        list->tail->next=tmp;
        list->tail->prev=NULL;
        (list->cnt)++;
    }
}

void pushToPlace(int n, type Type, void *a, list_t *list){
    if(n>list->cnt+1) printf("list to short\n");
    else if((n==0)||(n==list->cnt+1)) (n==0)? pushBack(Type, a, list) : pushFront(Type, a, list);
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
        getValue(Type, a, new);
        tmp->prev=tmp->prev->next=new;   
        (list->cnt)++;
    }
}

void popFront(list_t *list){
    if(list->cnt==0)
        printf("List empty\n");
    else{
        printValue(*list->head);
        node_t *tmp;
        tmp=list->head->prev;
        free(list->head);
        list->head=tmp;
        (list->cnt)--;
    }
}

void popBack(list_t *list){
    if(list->cnt==0)
        printf("List empty\n");
    else{
        printValue(*list->tail);
        node_t *tmp;
        tmp=list->tail->next;
        free(list->tail);
        list->tail=tmp;
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
        printValue(*tmp);
        free(tmp);
        (list->cnt)--;
    }
}
    
void printTailToHead(list_t list){
    if(list.cnt==0) printf("List empty\n");
    else{
        node_t *tmp;
        tmp=list.tail;
        while(tmp->next!=NULL){
            printValue(*tmp);
            tmp=tmp->next;
        }
        printValue(*tmp);
    }
}

void printHeadToTail(list_t list){
    if(list.cnt==0) printf("List empty\n");
    else{
        node_t *tmp;
        tmp=list.head;
        while(tmp->prev!=NULL){
            printValue(*tmp);
            tmp=tmp->prev;
        }
        printValue(*tmp);
    }
}

void printHead(list_t list){
    if(list.cnt==0) printf("List empty\n");
    else printValue(*list.head);
}

void printTail(list_t list){
    if(list.cnt==0) printf("List empty\n");
    else printValue(*list.tail);
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
