struct Node ;
typedef struct LinkedList * LinkedList_T; 

/* create new linkedlist type */
LinkedList_T LinkedList_new(void);

/* destroy linkedlist */
void LinkedList_free(struct LinkedList *q) ;

/* Gets the data stored in the first item of the list or NULL if the list is empty */
int LinkedList_first(LinkedList_T list);

/* Gets the data stored in the last item of the list or NULL if the list is empty */
int LinkedList_last(LinkedList_T list);

/* add linkedlist to the front of the list */
void LinkedList_add(LinkedList_T list, int value) ;

/* append linkedlist to the end of list */
void LinkedList_append(LinkedList_T list, int value) ;

/* print linkedlist  */
void LinkedList_print(LinkedList_T list) ;

/* print linkedlist reversely  */
void LinkedList_print_reverse(LinkedList_T list) ;


