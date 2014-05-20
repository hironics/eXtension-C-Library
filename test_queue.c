#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MAX 10

int main(int argc, char * argv[])
{
    Queue_T q;
    char * str;
    int val;
    int i;

    srand(time(NULL));

    q = Queue_new();
    for (val=0;val<MAX; val++){
        printf("inserting item #%d\n", val);
        i = rand()%MAX;
        Queue_insert(q, i%2?"hello":"world", i);
        //Queue_insert(q, "world", i);
    }

    Queue_first(q, &str, &val);
    printf("first item string is :%s, value is:%d\n", str, val);
    Queue_last(q, &str, &val);
    printf("rear item string is :%s, value is:%d\n", str, val);
    while(!Queue_isEmpty(q)){
        Queue_delete(q, &str, &val);
        printf("str is :%s, value is:%d\n", str, val);
    }
    printf("is stack empty? %s\n", Queue_isEmpty(q)? "yes": "no");

    Queue_free(q);
    return EXIT_SUCCESS;
}
