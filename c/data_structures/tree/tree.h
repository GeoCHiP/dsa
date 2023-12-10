#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

/************************
 * Binary Tree functions*
 * **********************/

/* Struct for the tree nodes. */
struct tree_node_t {
    int data;
    struct tree_node_t *left;
    struct tree_node_t *right;
};

/* Returns pointer to instace of type 'struct tree_tree_node_t'. */
struct tree_node_t *newTreeNode(int data);

/* Initializes binary tree with values entered to the stdin and returns pointer to him. */
struct tree_node_t *initPreorder();

/* Initializes binary search tree with values entered to the stdin and returns pointer to him. */
struct tree_node_t *initBST();

/* Traverse tree in preorder manner and prints data stored at nodes. */
void printPreorder(const struct tree_node_t *root);

/* Traverse tree in inorder manner and prints data stored at nodes. */
void printInorder(const struct tree_node_t *root);

/* Traverse tree in postorder manner and prints data stored at nodes. */
void printPostorder(const struct tree_node_t *root);

/* Inserts element in binary search tree. */
void insertBST(struct tree_node_t **root, int data);

/* Returns 1 if there is a node with data field equals key, otherwise 0. */
int searchBST(const struct tree_node_t *root, int key);

/* Returns count of nodes. Returns 0 either if root is NULL or root have no childred. */
int countTreeNodes(const struct tree_node_t *root);

/* Returns count of leaves. Returns 0 if root is NULL and 1 if root have no children. */
int countTreeLeaves(const struct tree_node_t *root);

/* Returns count of nodes with only one child. */
int countOneChildTreeNodes(const struct tree_node_t *root);

/* Returns max level of tree. Returns 0 either if root is NULL or have no children*/
int treeHeight(const struct tree_node_t *root);

/* Deletes all leafs of tree root points to. */
void deleteLeafs(struct tree_node_t **root);

/* Fully erases tree and releases memory. */
void eraseTree(struct tree_node_t **root);

#endif /* TREE_H */
