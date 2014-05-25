#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

struct hashmap{
    kv_p * buckets; // point to kv array
    //char ** keys;
    size_t size;
    size_t num_buckets;
};


hashmap_p hashmap_create()
{
    int i;
    hashmap_p hash = (hashmap_p) malloc (sizeof(struct hashmap));
    hash->size = 0;
    hash->num_buckets = DEFAULT_NUM_BUCKETS ;

    hash->buckets = (kv_p *) malloc(sizeof(kv_p ) * hash->num_buckets);

    for(i=0; i<DEFAULT_NUM_BUCKETS ; i++){
        hash->buckets[i] = NULL;
    }
    return hash;
}

size_t hashme(char * c)
{
    size_t hashvalue = 0;
    int i = 0;
    for(i=0; i<strlen(c); i++){
        hashvalue += c[i];
    }
    return hashvalue;
}

void hashmap_put(hashmap_p m, char* key, void* val, size_t len)
{
    size_t index = hashme(key)%m->num_buckets;
    kv_p k;
    kv_p tmp;

    tmp = (kv_p) malloc(sizeof(struct kv));
    tmp = (kv_p) malloc(sizeof(struct kv));
    tmp->key = key;
    tmp->val = val;
    tmp->next = NULL;

    k = m->buckets[index];
    /* first node */
    if(k==NULL){
        m->buckets[index] = tmp;
    }
    else{
        while(k->next != NULL){
            k = k->next;
        }
        k->next = tmp;
    }
}

void * hashmap_get(hashmap_p m, char * key)
{
    size_t index = hashme(key)%m->num_buckets;
    kv_p k;
    k = m->buckets[index];
    if(k==NULL){
        return NULL;
    }
    while(k){
        if(strcmp(key, k->key)==0)
            return k->val;
        k = k->next;    
    }
    return NULL;
}


void hashmap_remove(hashmap_p m, char* key)
{
    size_t index = hashme(key)%m->num_buckets;
    kv_p iter, prev;
    int i=0;

    iter = m->buckets[index];
    while(iter){
        i++;
        prev = iter;
        if(strcmp(key, iter->key) == 0)
            break;

        iter = iter->next;    
    }

    if(i==1){
        m->buckets[index] = iter->next; 
    }else{
        prev->next = iter->next;
    }
    free(iter);
}

void _free_list(kv_p p)
{
    if (p==NULL)
        return;
    if(p->next != NULL)
        _free_list(p->next);
    free(p);
}

void hashmap_free(hashmap_p h)
{
    size_t i;

    for(i=0;i<h->num_buckets; i++){
        _free_list(h->buckets[i]);
    }
    free(h);
}
