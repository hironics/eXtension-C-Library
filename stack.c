#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct Node {
    const char *key;
    int value;
    struct Node *next;
    };

struct Stack {
    struct Node *first;
    };

Stack_T Stack_new(void) 
{ 
    Stack_T s; 
    s = (Stack_T ) malloc(sizeof(struct Stack )); 
    s->first = NULL; 
    return s;
}

void Stack_free(Stack_T s) 
{ 
    struct Node *p; 
    struct Node *nextp; 
    for (p = s->first; p != NULL; p = nextp) { 
        nextp = p->next; 
        free(p); 
    } 
    free(s); 
} 


void Stack_push(Stack_T s, const char *key, int value) 
{ 
    struct Node *p = (struct Node*)malloc(sizeof(struct Node)); 
    p->key = key; 
    p->value = value; 
    p->next = s->first; 
    s->first = p; 
} 

void Stack_pop(Stack_T s, char **key, int * value) 
{ 
    struct Node * tmp;
    if(s->first == NULL)
        return;
    tmp = s->first;    
    *value = tmp->value;
    *key = tmp->key;

    s->first = tmp->next;
    return;
} 

void Stack_top(Stack_T s, char **key, int *value)
{
    struct Node * tmp;
    if(s->first == NULL)
        return;
    tmp = s->first;    
    *value = tmp->value;
    *key = tmp->key;
    return;
}

int Stack_isEmpty(Stack_T s) 
{ 
    return (s->first == NULL);
} 
 

