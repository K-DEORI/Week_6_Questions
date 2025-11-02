#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void removeDuplicates(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL && curr->next != NULL) {
        struct Node *temp = curr;
        while (temp->next != NULL) {
            if (curr->data == temp->next->data) {
                struct Node *dup = temp->next;
                temp->next = temp->next->next;
                free(dup);
            } else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

