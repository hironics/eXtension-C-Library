
int Stack_search(struct Stack *t, const char *key, int *value) 
{ 
    struct Node *p; 
    for (p = t->first; p != NULL; p = p->next) 
        if (strcmp(p->key, key) == 0) { 
            *value = p->value; 
            return 1;
        }
    return 0;
}

