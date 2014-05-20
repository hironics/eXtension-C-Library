
#ifndef _QUEUE_H
#define _QUEUE_H
/*
Queue provides functions like 
pop, push etc.

it allows user push a string and value together in one shot
*/
typedef struct Queue * Queue_T;

Queue_T Queue_new(void);
void Queue_free(struct Queue *q) ;
/*
    insert an item at the rear of the queue
*/
void Queue_insert(struct Queue *q, const char *key, int value) ;
/*
    delete an item at the front of the queue
*/
void Queue_delete(struct Queue *q, char **key, int *value) ;
/*
    return the front item of the queue
*/
void Queue_first(struct Queue *q, char **key, int *value) ;
/*
    return the rear item of the queue
*/
void Queue_last(struct Queue *q, char **key, int *value) ;
/*
    test if the queue if empty 
    return 1 as yes
*/
int Queue_isEmpty(struct Queue *q);

#endif     
