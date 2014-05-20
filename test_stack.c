#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define MAX 50

int main(int argc, char * argv[])
{
    Stack_T s;
    char * str;
    int val;

    srand(time(NULL));

    s = Stack_new();
    for (val=0;val<MAX; val++){
        Stack_push(s, "hello", rand()%MAX);
        Stack_push(s, "world", rand()%MAX);
    }

    Stack_top(s, &str, &val);
    printf("top item string is :%s, value is:%d\n", str, val);
    while(!Stack_isEmpty(s)){
        Stack_pop(s, &str, &val);
        printf("str is :%s, value is:%d\n", str, val);
    }

    printf("is stack empty? %s\n", Stack_isEmpty(s)? "yes": "no");

    Stack_free(s);
    return EXIT_SUCCESS;
}
