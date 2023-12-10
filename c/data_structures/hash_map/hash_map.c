#include <stdio.h>
#include <stdlib.h>

#define HASH_ARRAY_SIZE 20

struct hash_item_t {
    int data;
    int key;
};

struct hash_item_t *hashArray[HASH_ARRAY_SIZE] = {0};

int hashCode(int key) {
    return key % HASH_ARRAY_SIZE;
}

void hashInsert(int data, int key) {
    struct hash_item_t *item = (struct hash_item_t *)malloc(sizeof(struct hash_item_t));
    item->data = data;
    item->key = key;

    int hashIndex = hashCode(key);
    
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        ++hashIndex;
        hashIndex %= HASH_ARRAY_SIZE;
    }

    hashArray[hashIndex] = item;
}

struct hash_item_t *hashSearch(int key) {
    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }

        ++hashIndex;
        hashIndex %= HASH_ARRAY_SIZE;
    }

    return NULL;
}
