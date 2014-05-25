#include <stdlib.h>
#include <stdbool.h>
 
#include "heap.h"
 
#define CMP(a, b) ((a) <= (b))
 
static const unsigned int base_size = 10;
 
// Prepares the heap for use
heap_p heap_init()
{
    heap_p h;
    h = (heap_p) malloc(sizeof(struct heap));
    h->size = base_size;
    h->count = 0;
    h->data = (int *) malloc(sizeof(type) * base_size);
    return h;
}
 
// Inserts element to the heap
void heap_push(heap_p h, type value)
{
	unsigned int index, parent;
 
	// Resize the heap if it is too small to hold all the data
	if (h->count == h->size)
	{
		h->size <<= 1;
		h->data = realloc(h->data, sizeof(type) * h->size);
	}
 
	// Find out where to put the element and put it
    // initiall it just append to the list, then do a cmp
	for(index = h->count++; index; index = parent)
	{
		parent = (index - 1) >> 1;
		if CMP(h->data[parent], value) 
            break;
		h->data[index] = h->data[parent];
	}
	h->data[index] = value;
}
 
// Removes the biggest element from the heap
void heap_pop(heap_p h)
{
	unsigned int index, swap, other;
 
	// Remove the smallest element
	type temp = h->data[--h->count];
 
	// Resize the heap if it's consuming too much memory
	if ((h->count <= (h->size >> 2)) && (h->size > base_size))
	{
		h->size >>= 1;
		h->data = realloc(h->data, sizeof(type) * h->size);
	}
 
	// Reorder the elements
	for(index = 0; true; index = swap)
	{
		// Find the child to swap with
		swap = (index << 1) + 1;
		if (swap >= h->count) 
            break; // If there are no children, the heap is reordered
		other = swap + 1;
		if ((other < h->count) && CMP(h->data[other], h->data[swap])) 
            swap = other;
		if CMP(temp, h->data[swap]) 
            break; // If the smaller child is less than or equal to its parent, the heap is reordered
 
		h->data[index] = h->data[swap];
	}
	h->data[index] = temp;
}
 
// Heapifies a non-empty array
void heapify(type data[], unsigned int count)
{
	unsigned int item, index, left, right;
	type temp;
 
	// Move every non-leaf element to the right position in its subtree
	item = (count >> 1) - 1;
	while(true)
	{
		// Find the position of the current element in its subtree
		temp = data[item];
		for(index = item; true; index = left)
		{
			// Find the child to swap with
			left = (index << 1) + 1;
			if (left >= count) break; // If there are no children, the current element is positioned
			right = left + 1;
			if ((right< count) && CMP(data[right], data[left])) left = right; //right is smaller, so change right to left
			if CMP(temp, data[left]) 
                break; // If the bigger child is smaller than or equal to the parent, the heap is reordered
 
			data[index] = data[left];
		}
		if (index != item) data[index] = temp;
 
		if (!item) return;
		--item;
	}
}
