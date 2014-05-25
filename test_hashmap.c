#include <stdio.h>

#include "hashmap.h"

int main(int argc, char * argv[])
{
    hashmap_p p;
    int i;
    char * c="aa";

    p = Hashmap_create();
    printf("hash value for aa: %d\n", Hashmap_hash("aa"));
    printf("hash value for bb: %d\n", Hashmap_hash("bb"));
    printf("hash value for ac: %d\n", Hashmap_hash("ac"));
    printf("hash value for bc_d: %d\n", Hashmap_hash("bc_d"));

    Hashmap_put(p, "aa", "vv", 2);
    Hashmap_put(p, "bb", "bv3", 3);
    Hashmap_put(p, "ac", "i'm ac", 6);
    printf("get key 'aa' : %s\n", (char *)Hashmap_get(p, "aa"));
    printf("get key 'bb' : %s\n", (char *)Hashmap_get(p, "bb"));
    printf("get key 'ac' : %s\n", (char *)Hashmap_get(p, "ac"));

    puts("remove aa");
    Hashmap_remove(p, "aa");
    printf("get key 'aa' : %s\n", (char *)Hashmap_get(p, "aa"));
    puts("remove bb");
    Hashmap_remove(p, "bb");
    printf("get key 'bb' : %s\n", (char *)Hashmap_get(p, "bb"));
    printf("get key 'ac' : %s\n", (char *)Hashmap_get(p, "ac"));

    puts("free the hashmap");
    Hashmap_free(p);

    getchar();
    return 0;
}
