#ifndef __HASHMAP_H__
#define __HASHMAP_H__

/* A C implementation of a Hash Map. 
   Uses string keys but has void pointer values */

#include <stdlib.h>

#define DEFAULT_NUM_BUCKETS 365 

/*
key value pair
*/
struct kv{
    char* key;
    void* val;
    struct kv * next;
};

typedef struct kv * kv_p;

typedef struct hashmap * hashmap_p;

/* Create a new hashmap. The hashmap created by this method must be eventually 
   destroyed by a call to hashmap_free to avoid memory leak */
hashmap_p Hashmap_create();

/*
free hashmap
*/

void Hashmap_free(hashmap_p h);

/* Place an entry with the value val and length len into the hashmap m and associate
   it with the key key. The key and value are copied by value, not by pointer,
   so if they were created on the heap, they must be freed later. */
void Hashmap_put(hashmap_p m, char* key, void* val, size_t len);

/* Get the value of the entry in hashmap m associated with key key */
void* Hashmap_get(hashmap_p m, char* key);

/* Remove the item associated with the key key in the hashmap m. The memory for the
   entry is completely freed, so use hashmap_get and make a deep copy if you wish to
   retain it. */
void Hashmap_remove(hashmap_p m, char* key);

/* Hash function for the key key. This function is not meant to be called directly */
size_t Hashmap_hash(char * key);
#endif
