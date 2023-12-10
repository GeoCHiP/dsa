#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

struct tree_node_t *newTreeNode(int data) {
    struct tree_node_t *treeNode = (struct tree_node_t *)malloc(sizeof(struct tree_node_t));

    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;

    return treeNode;
}

struct tree_node_t *initPreorder() {
    static int level = 0;

    int data = 0;
    printf("Level %d. Enter data (letter for no data): ", level);

    int input = scanf("%d", &data);
    while (getchar() != '\n');

    struct tree_node_t *root = NULL;
    if (input) {
        root = newTreeNode(data);

        ++level;
        root->left = initPreorder();
        ++level;
        root->right = initPreorder();
    }
    --level;

    return root;
}

struct tree_node_t *initBST() {
    int data = 0;

    puts("Enter data (letter for no data):");
    int input = scanf("%d", &data);

    if (!input) {
        return NULL;
    }

    struct tree_node_t *root = newTreeNode(data);
    input = scanf("%d", &data);
    
    while (input) {
        struct tree_node_t *next = root;
        struct tree_node_t *current = root;

        while (next != NULL) {
            current = next;
            
            if (data < current->data) {
                next = current->left;
            }
            else {
                next = current->right;
            }

        }

        if (data < current->data) {
            current->left = newTreeNode(data);
        } else {
            current->right = newTreeNode(data);
        }

        input = scanf("%d", &data);
    }

    return root;
}

void printPreorder(const struct tree_node_t *root) {
    if (root == NULL) {
        return;
    }

    static int level = 0;

    printf("%d ", root->data);

    ++level;
    printPreorder(root->left);
    printPreorder(root->right);
    --level;
    
    if (level == 0) {
        putchar('\n');
    }
}

void printInorder(const struct tree_node_t *root) {
    if (root == NULL) {
        return;
    }

    static int level = 0;
    
    ++level;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
    --level;

    if (level == 0) {
        putchar('\n');
    }
}

void printPostorder(const struct tree_node_t *root) {
    if (root == NULL) {
        return;
    }

    static int level = 0;

    ++level;
    printPostorder(root->left);
    printPostorder(root->right);
    --level;

    printf("%d ", root->data);

    if (level == 0) {
        putchar('\n');
    }
}

void insertBST(struct tree_node_t **root, int data) {
    if (*root == NULL) {
        *root = newTreeNode(data);
        printf("%d now is a root of the tree\n", data);
        return;
    }

    struct tree_node_t *current = *root;
    struct tree_node_t *next = *root;

    while (next != NULL) {
        current = next;

        if (data < current->data) {
            next = current->left;
        } else {
            next = current->right;
        }
    }

    if (data < current->data) {
        current->left = newTreeNode(data);
        printf("%d now is a left child of %d\n", data, current->data);
    } else {
        current->right = newTreeNode(data);
        printf("%d now is a right child of %d\n", data, current->data);
    }
}

int searchBST(const struct tree_node_t *root, int key) {
    if (root == NULL) {
        printf("Given pointer to the root of the tree can't be NULL!");
        return 0;
    }

    const struct tree_node_t *current = root;
    const struct tree_node_t *next = root;

    while((current->data != key) && (next != NULL)) {
        current = next;

        if (key < current->data) {
            next = current->left;
        } else {
            next = current->right;
        }
    }

    if (current->data == key) {
        return 1;
    } else {
        return 0;
    }
}

int countTreeNodes(const struct tree_node_t *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countTreeNodes(root->left) + countTreeNodes(root->right);
}

int countTreeLeaves(const struct tree_node_t *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countTreeLeaves(root->left) + countTreeLeaves(root->right);
}

int countOneChildTreeNodes(const struct tree_node_t *root) {
    if (root == NULL) {
        return 0;
    }

    static int count = 0;
    static int level = 0;

    if ((root->left == NULL && root->right != NULL)
            || (root->left != NULL && root->right == NULL)) {
        ++count;
    }

    ++level;
    countOneChildTreeNodes(root->left);
    countOneChildTreeNodes(root->right);
    --level;

    return count;
}

int treeHeight(const struct tree_node_t *root) {
    static int level = 0;
    
    if (root == NULL) {
        if (level == 0) {
            return 0;
        } else {
            return level - 1;
        }
    }

    ++level;
    int lhs = treeHeight(root->left);
    int rhs = treeHeight(root->right);
    --level;

    return lhs > rhs ? lhs : rhs;
}

void deleteLeafs(struct tree_node_t **root) {
    if (*root == NULL) {
        return;
    }

    if ((*root)->left == NULL && (*root)->right == NULL) {
        printf("%d was deleted\n", (*root)->data);
        free(*root);
        *root = NULL;
        return;
    }

    deleteLeafs(&(*root)->left);
    deleteLeafs(&(*root)->right);
}

void eraseTree(struct tree_node_t **root) {
    if (*root == NULL) {
        return;
    }

    static int level = 0;

    ++level;
    eraseTree(&(*root)->left);
    eraseTree(&(*root)->right);
    --level;
    
    free(*root);

    if (level == 0) {
        *root = NULL;
    }
}
