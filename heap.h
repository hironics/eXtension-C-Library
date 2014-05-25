#ifndef _HEAP_H
#define _HEAP_H
/*
auto resize the heap after you add new items
*/
 
typedef int type;
 
struct heap
{
	unsigned int size; // Size of the allocated memory (in number of items)
	unsigned int count; // Count of the elements in the heap
	type *data; // Array with the elements
};

typedef struct heap * heap_p;
 
heap_p heap_init(void);
void heap_push(heap_p h, type value);
void heap_pop(heap_p h);
 
// Returns the biggest element in the heap
#define heap_front(h) (*(h)->data)
 
// Frees the allocated memory
#define heap_free(h) (free(h->data))
 
void heapify(type data[], unsigned int count);

#endif
