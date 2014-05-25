#ifndef _BSTREE_H
#define _BSTREE_H


#include <stdlib.h>
/*
balance search tree
*/

struct Node{
    void * val;
    struct Node *left;
    struct Node *right;
};

typedef struct Node * node_p;

struct Bstree{
    size_t size;
    node_p root;
};

typedef struct Bstree * Bstree_p;

Bstree_p Bstree_create();

size_t Bstree_size(node_p p);

size_t Bstree_maxDepth(node_p p);

void Bstree_put(Bstree_p t, void * val, int n);

void Bstree_remove(Bstree_p t, void * val);

void Bstree_free(Bstree_p t);

#endif
