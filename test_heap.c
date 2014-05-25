#include <stdio.h>
#include "heap.h"

int main()
{
    int i;
    int arry[10] = {3, 4 , 6, 5, 7, 0, 2, 1, 9, 8};
    heap_p h;
    h = heap_init();
    for(i=0; i<h->size; i++){
        printf ("%d, ", h->data[i]);
    }
    puts("");
    heapify(arry, 10);
    for(i=0; i<10; i++){
        printf("%d, ", arry[i]);
    }
    puts("");

    return 0;
}
