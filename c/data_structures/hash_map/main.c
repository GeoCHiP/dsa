#include <pthread.h>
#include <stdio.h>

#include "hash_map.h"

int main(void) {

    struct hash_item_t *dummyItem = NULL;

    for (int i = 0; i < 20; ++i) {
        hashInsert(5 + i * 2, i + 7);
    }

    dummyItem = hashSearch(9);
    
    if (dummyItem != NULL) {
        printf("Key found: %d\n", 9);
    } else {
        printf("Key not found!\n");
    }

    return 0;
}
