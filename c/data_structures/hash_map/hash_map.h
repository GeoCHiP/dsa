#ifndef HASH_MAP_H
#define HASH_MAP_H


struct hash_item_t {
    int data;
    int key;
};

int hashCode(int key);

void hashInsert(int data, int key);

struct hash_item_t *hashSearch(int key);


#endif /* HASH_MAP_H */
