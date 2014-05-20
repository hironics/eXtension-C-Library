#ifndef _STACK_H
#define _STACK_H
/*
Stack provides functions like 
pop, push etc.

it allows user push a string and value together in one shot
*/
typedef struct Stack * Stack_T;

Stack_T Stack_new(void);
void Stack_free(struct Stack *s) ;
void Stack_push(struct Stack *s, const char *key, int value) ;
void Stack_pop(struct Stack *s, char **key, int *value) ;
void Stack_top(struct Stack *s, char **key, int *value) ;
int Stack_isEmpty(struct Stack *s);

#endif     
