#include <stdio.h>
#include "bstree.h"


void print_preorder(node_p  tree)
{
    if (tree)
    {
        printf("%d, ",tree->val);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}


int main(int argc, char * argv[])
{
    Bstree_p t;
    int a[4] = {3, 1, 2, 4};

    t = Bstree_create();

    puts("insert" " items");
    Bstree_put(t, a[0]);
    Bstree_put(t, a[1]);
    Bstree_put(t, a[2]);
    Bstree_put(t, a[3]);
    /*
    Bstree_put(t, "ab", 2);
    Bstree_put(t, "ac", 2);
    Bstree_put(t, "ad", 2);
    Bstree_put(t, "ae", 2);
    */

    printf("print\n");
    print_preorder(t->root);
    printf("\n");
    print_inorder(t->root);
    printf("\n");
    print_postorder(t->root);
    printf("\n");

    Bstree_remove(&(t->root), a[0]);
    puts("after remove , print again");
    print_inorder(t->root);
    printf("\n");

    printf("tree size is %d\n", Bstree_size(t->root));
    printf("depth issize is %d\n", Bstree_maxDepth(t->root));
    puts("free the tree");
    Bstree_free(t);

    return 0;
}
