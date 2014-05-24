#include <stdio.h>
#include "linkedlist.h"

/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    LinkedList_T  list;
    int i;

    list = LinkedList_new();
    // Insert 6.  So linked list becomes 6->NULL
    printf("add new item\n");
    for(i=0; i<10; i++){
        LinkedList_add(list, i) ;
    }

    printf("append new item\n");
    for(i=100; i<110; i++){
        LinkedList_append(list, i) ;
    }

    printf("print list item\n");
    LinkedList_print(list);
    printf("print list item reverse\n");
    LinkedList_print_reverse(list);
    printf("the first item is: %d\n", LinkedList_first(list));
    printf("the last item is: %d\n", LinkedList_last(list));

    getchar();
    return 0;
}

