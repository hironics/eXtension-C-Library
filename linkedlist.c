#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"
 
// A linked list node
struct Node {
    int data;
    struct Node *next;
    };

struct LinkedList {
    struct Node *first;
    int size;
    bool enabled; //need this to avoid user add entries before New the list
    };

/* create new linkedlist type */
LinkedList_T LinkedList_new(void)
{
   LinkedList_T list ;
   list = (LinkedList_T) malloc(sizeof(struct LinkedList));
   list->first = NULL;
   list->size = 0;
   list->enabled = true;
   return list;
}

/* destroy linkedlist */
void LinkedList_free(LinkedList_T list) 
{
    struct Node * current;
    struct Node * tmp;
    if (list->size == 0){
        free(list);
        return;
    }
    current = list->first;
    do{
        tmp = current;
        current = current->next;
        free(tmp);
    } while(current);
    return;
}

/* Gets the data stored in the first item of the list or NULL if the list is empty */
int  LinkedList_first(LinkedList_T list)
{
    if (list->size == 0){
        return NULL;
    }
    return list->first->data;
}

/* Gets the data stored in the last item of the list or NULL if the list is empty */
int LinkedList_last(LinkedList_T list)
{
    struct Node * current;
    if (list->size == 0){
        return NULL;
    }
    current = list->first;
    while(current->next != NULL){
        current = current->next;
    }
    return current->data;
}

/* add linkedlist to the front of the list */
void LinkedList_add(LinkedList_T list, int value) 
{
    struct Node * tmp;

    if(! list->enabled){
        return;
    }
    struct Node * newitem = (struct Node *)malloc(sizeof(struct Node));
    newitem->data = value;
    newitem->next = NULL;

    tmp = list->first ;
    if(tmp != NULL){ //already has some member
        newitem->next = tmp;
    }
    list->first = newitem;
    list->size += 1;

}

/* append linkedlist to the end of list */
void LinkedList_append(LinkedList_T list, int value) 
{
    struct Node * newitem = (struct Node *) malloc(sizeof(struct Node));
    struct Node * iter;
    newitem->data = value;
    newitem->next = NULL;

    iter = list->first;
    while(iter->next != NULL){
        iter = iter->next;
    }
    iter->next = newitem;

    /*list size increase by 1 */
    list->size += 1;
}

/* print linkedlist  */
void LinkedList_print(LinkedList_T list) 
{
    struct Node * current;
    if(list->size == 0){
        return;
    }
    current = list->first;
    do {
        printf("%d, ", current->data);
        current = current->next;
    }while(current != NULL);
    printf("\n");
}

void _print_reverse(struct Node * node)
{
    if(node){
        _print_reverse(node->next);
        printf("%d, ", node->data);
    }
}

/* print linkedlist reversely  */
void LinkedList_print_reverse(LinkedList_T list) 
{
    _print_reverse(list->first);
}


