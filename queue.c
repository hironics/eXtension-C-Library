#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Node {
    const char *key;
    int value;
    struct Node *next;
    };

struct Queue {
    struct Node *first;
    struct Node *last;
    };

/*
use linked list to create the queue
    front node -> node -> node -> rear node

*/

Queue_T Queue_new(void) 
{ 
    Queue_T q; 
    q = (Queue_T) malloc(sizeof(struct Queue)); 
    q->first = NULL; 
    q->last = NULL; 
    return q;
}

void Queue_free(Queue_T q) 
{ 
    struct Node *p; 
    struct Node *nextp; 
    for (p = q->first; p != NULL; p = nextp) { 
        nextp = p->next; 
        free(p); 
    } 
    free(q); 
} 

void Queue_insert(struct Queue *q, const char *key, int value) 
{
    struct Node *p = (struct Node *) malloc(sizeof(struct Node)); 
    p->key = key;
    p->value = value;

    if(q->last == NULL){
        q->last = p;
        q->first = p;
    }
    else {
        q->last->next = p;
        q->last = p;
    }
}

void Queue_delete(struct Queue *q, char **key, int *value) 
{
    struct Node * tmp;
    if( (q->first == q->last)  && (q->last == NULL)){
        return;
    }
    tmp = q->first;
    *key = tmp->key;
    *value = tmp->value;

    q->first = tmp->next;
    return 0;
}

int Queue_isEmpty(Queue_T q) 
{ 
    return (q->first == NULL);
} 


void Queue_first(struct Queue *q, char **key, int *value) 
{
    struct Node * tmp;
    if(q->first == NULL)
        return;
    tmp = q->first;    
    *value = tmp->value;
    *key = tmp->key;
    return;
}

void Queue_last(struct Queue *q, char **key, int *value) 
{
    struct Node * tmp;
    if(q->last == NULL)
        return;
    tmp = q->last ;    
    *value = tmp->value;
    *key = tmp->key;
    return;
}
