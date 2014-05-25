xclib
=====

Extension library for C, including Queue, Stack, Hashmap, LinkedList, Heap, Binary Search Tree and Common String functions. C Standard library has some popular functions including memory allocation, assert, time and basic string functions. However, it's still a burden to recreate some ubiquitous data structure and algorithm.

### Stack

* Stack_new
* Stack_push
* Stack_pop
* Stack_isEmpty 

### Queue
* Queue_T Queue_new(void);
* void Queue_free(struct Queue *q) ;
* void Queue_insert(struct Queue *q, const char *key, int value) ;
* void Queue_delete(struct Queue *q, char **key, int *value) ;
* void Queue_first(struct Queue *q, char **key, int *value) ;
* void Queue_last(struct Queue *q, char **key, int *value) ;
* int Queue_isEmpty(struct Queue *q);


### Hashmap 

* Hashmap_create
* Hashmap_hash: hash function, which accepts sring, returns size_t value
* Hashmap_put
* Hashmap_get
* Hashmap_remove

### LinkedList

### heap

* heap_init
* heap_push
* heap_pop
* heap_front
* heap_free
* heapify
### Bstree 
Binary Search Tree


### String Manuplication Functions

* str_startswith
* str_endswith
