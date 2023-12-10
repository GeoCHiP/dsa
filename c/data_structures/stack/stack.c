#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

/********************************
 * Singly linked list functions *
 ********************************/

struct list_node_t *newNode(int data) {
    struct list_node_t *stackNode = (struct list_node_t *)malloc(sizeof(struct list_node_t));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

struct list_node_t *initStack(void) {
    puts("Enter numbers (input is terminated by not a number):");
    
    struct list_node_t *head = NULL;
    int data = 0;
    int input = scanf("%d", &data);
    
    while (input) {
        struct list_node_t *temp = newNode(data);
        temp->next = head;
        head = temp;
        input = scanf("%d", &data);
    }
    
    while (getchar() != '\n');
    return head;
}

int isEmpty(const struct list_node_t *head) {
    return (head == NULL);
}

int length(const struct list_node_t *head) {
    if (isEmpty(head)) {
        return 0;
    }

    const struct list_node_t *current = head;

    int length = 0;
    while (current != NULL) {
        current = current->next;
        length++;
    }

    return length;
}

int lengthRec(const struct list_node_t *head) {
    if (isEmpty(head)) {
        return 0;
    }

    return 1 + lengthRec(head->next);
}

void push(struct list_node_t **head, int data) {
    struct list_node_t *stackNode = newNode(data);
    stackNode->next = *head;
    *head = stackNode;
    printf("%d pushed to the stack\n", data);
}

int pop(struct list_node_t **head) {
    if (isEmpty(*head)) {
        puts("Given pointer to the head of list can't be NULL");
        return 0;
    }

    struct list_node_t *temp = (*head);
    int popped = temp->data;

    (*head) = (*head)->next;
    free(temp);

    printf("%d popped from the stack\n", popped);
    return popped;
}

void insertAfter(struct list_node_t *prevNode, int data) {
    if (isEmpty(prevNode)) {
        puts("Given previes node can't be NULL!");
        return;
    }

    struct list_node_t *stackNode = newNode(data);
    stackNode->next = prevNode->next;
    prevNode->next = stackNode;
    
    printf("%d inserted after %d\n", data, prevNode->data);
}

void append(struct list_node_t **head, int data) {
    struct list_node_t *stackNode = newNode(data);

    if (isEmpty(*head)) {
        *head = stackNode;
    } else {
        struct list_node_t *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = stackNode;
    }

    printf("%d appended to the stack\n", data);
}

void deleteNodeKey(struct list_node_t **head, int key) {
    if (isEmpty(*head)) {
        puts("Given pointer to the head of can't be NULL");
        return;
    }

    struct list_node_t *temp = *head;

    if ((*head)->data == key) {
        *head = (*head)->next;
        free(temp);
        printf("%d deleted from the stack\n", key);
        return;
    }

    struct list_node_t *prev = temp;

    while (temp != NULL && temp->data != key ) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("There is no %d in the stack\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the stack\n", key);
}

int deleteNodeAt(struct list_node_t **head, int position) {
    if (isEmpty(*head)) {
        puts("Given pointer to the head of list can't be NULL");
        return 0;
    }

    struct list_node_t *temp = *head;

    if (position == 0) {
        return pop(head);
    }

    struct list_node_t *prev = temp;

    for (int i = 0; (temp != NULL) && (i < position); ++i) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        puts("There is no element at the given position!");
        return 0;
    }

    int deleted = temp->data;
    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the stack\n", deleted);
    return deleted;
}

int GetNth(const struct list_node_t *head, int index) {
    if (isEmpty(head)) {
        puts("Given pointer to the head of list can't be NULL!");
        return 0;
    }

    const struct list_node_t *current = head;

    for (int i = 0; (current != NULL) && (i < index); ++i) {
        current = current->next;
    }

    if (head == NULL) {
        printf("There is no node with index %d!\n", index);
        return 0;
    } else {
        return current->data;
    }
}

int GetNthFromLast(const struct list_node_t *head, int index) {
    if (isEmpty(head)) {
        puts("Given pointer to the head of list can't be NULL!");
        return 0;
    }
    if (index <= 0) {
        puts("Index must be >= 1");
        return 0;
    }

    int len = length(head);
    if (index > len) {
        printf("There is no node with index %d\n", -index);
        return 0;
    }

    const struct list_node_t *current = head;

    for (int i = 0; i < len - index; ++i) {
        current = current->next;
    } 

    return current->data;
}


int search(const struct list_node_t *head, int key) {
    if (isEmpty(head)) {
        puts("Given pointer to the head can't be NULL!");
        return 0;
    }

    const struct list_node_t *current = head;

    while (current != NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int searchRec(const struct list_node_t *head, int key) {
    if (isEmpty(head)) {
        return 0;
    }

    if (head->data == key) {
        return 1;
    } else {
        return searchRec(head->next, key);
    }
}

void printList(const struct list_node_t *head) {
    if (isEmpty(head)) {
        puts("Stack is empty!");
        return;
    }

    const struct list_node_t *current = head;
    puts("Data in stack:");
    while (current->next != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("%d -> NULL\n", current->data);
}

void eraseList(struct list_node_t **head) {
    puts("Erasing stack...");
    while (*head != NULL) {
        struct list_node_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        
    }
}
