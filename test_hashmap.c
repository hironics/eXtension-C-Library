#include <stdio.h>

#include "hashmap.h"

int main(int argc, char * argv[])
{
    hashmap_p p;
    int i;
    char * c="aa";

    p = hashmap_create();
    printf("hash value for aa: %d\n", hashme("aa"));
    printf("hash value for bb: %d\n", hashme("bb"));
    printf("hash value for ac: %d\n", hashme("ac"));
    printf("hash value for bc_d: %d\n", hashme("bc_d"));

    hashmap_put(p, "aa", "vv", 2);
    hashmap_put(p, "bb", "bv3", 3);
    hashmap_put(p, "ac", "i'm ac", 6);
    printf("get key 'aa' : %s\n", (char *)hashmap_get(p, "aa"));
    printf("get key 'bb' : %s\n", (char *)hashmap_get(p, "bb"));
    printf("get key 'ac' : %s\n", (char *)hashmap_get(p, "ac"));

    puts("remove aa");
    hashmap_remove(p, "aa");
    printf("get key 'aa' : %s\n", (char *)hashmap_get(p, "aa"));
    puts("remove bb");
    hashmap_remove(p, "bb");
    printf("get key 'bb' : %s\n", (char *)hashmap_get(p, "bb"));
    printf("get key 'ac' : %s\n", (char *)hashmap_get(p, "ac"));

    puts("free the hashmap");
    hashmap_free(p);

    getchar();
    return 0;
}
