/*
binary search tree

*/
#include <stdlib.h>
#include <stdio.h>
#include "bstree.h"

Bstree_p Bstree_create()
{
    Bstree_p t = (Bstree_p) malloc(sizeof(struct Bstree));
    t->root = NULL;
    t->size = 0;
    return t;
}


void _insert(node_p * tree, void * val)
{
    node_p temp = NULL;
    if(!(*tree))
    {
        temp = (node_p)malloc(sizeof(struct Node));
        temp->left = temp->right = NULL;
        temp->val= val;
        *tree = temp;
        return;
    }

    if(*((int *)val) < (*tree)->val)
    {
        _insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->val)
    {
        _insert(&(*tree)->right, val);
    }

}

void Bstree_put(Bstree_p t, void * val, int n)
{
    _insert( &(t->root), val );
    t->size += 1;
    return;
}


void print_inorder(node_p  tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d, ",*((int *)(tree->val)));
        print_inorder(tree->right);
    }
}

void print_postorder(node_p  tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d, ",*((int *)(tree->val)));
    }
}

void _free(node_p node)
{
    if (node)
    {
        _free(node->left);
        _free(node->right);
        free(node);
    }
}

void Bstree_free(Bstree_p  t)
{
    _free(t->root);
    free(t);
}

node_p search(node_p * tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->val)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->val)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->val)
    {
        return *tree;
    }
}

void Bstree_remove(Bstree_p t, void * val)
{
    return ;
}

size_t Bstree_size(node_p p)
{
    if(p == NULL){
        return 0;
    }
    else{
        return(Bstree_size(p->left) + 1 + Bstree_size(p->right));
    }
}

size_t Bstree_maxDepth(node_p p)
{
    if (p == NULL){
        return 0;
    } else {
        int l = Bstree_maxDepth(p->left);
        int r = Bstree_maxDepth(p->right);
        return ((l>r)? l+1 : r+1);
    }
}
