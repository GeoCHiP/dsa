#ifndef STACK_H
#define STACK_H

/********************************
 * Singly linked list functions *
 ********************************/

/* Struct for stack nodes. */
struct list_node_t {
    int data;
    struct list_node_t *next;
};

/* Retuns pointer to instance of type 'struct list_node_t'. */
struct list_node_t *newNode(int data);

/* Initializes stack with values entered to stdin and returns pointer to him. */
struct list_node_t *initStack(void);

/* Returns 0 if head is NULL, otherwise 1. */
int isEmpty(const struct list_node_t *head);

/* Returns count of nodes in the stack.
 * Iterative method.                   */
int length(const struct list_node_t *head);

/* Returns count of nodes in the stack.
 *  Recursive method.                  */
int lengthRec(const struct list_node_t *head);

/* Pushes data to the stack. */
void push(struct list_node_t **head, int data);

/* Pops data from the stack and returns it. */
int pop(struct list_node_t **head);

/* Inserts data after element the prevNode points to. */
void insertAfter(struct list_node_t *prevNode, int data);

/* Appends data to the end of the stack. */
void append(struct list_node_t **head, int data);

/* Deletes the first occurence the key in the stack. */
void deleteNodeKey(struct list_node_t **head, int key);

/* Deletes node at the given position and returns its data. 
 * Indexing starts from 0.
 * If pointer to the head is NULL, returns 0.
 * If there is no node at given position, returns 0.       */
int deleteNodeAt(struct list_node_t **head, int position);

/* Returns data stored at Nth node in the stack.  
 * Indexing starts from 0.                      */
int GetNth(const struct list_node_t *head, int index);

/* Returns data stored at Nth node from the end in the list.
 * Index of first element from the end is 1.                */
int GetNthFromLast(const struct list_node_t *head, int index);

/* Returns 1 if there is a node with data equals key, otherwise 0.
 * Iterative method.                                              */
int search(const struct list_node_t *head, int key);

/* Returns 1 if there is a node with data equals key, otherwise 0.
 * Recursive method.                                              */
int searchRec(const struct list_node_t *head, int key);

/* Prints the linked list to stdout */
void printList(const struct list_node_t *head);

/* Fully erases linked list and releases memory. */
void eraseList(struct list_node_t **head);

#endif // STACK_H
