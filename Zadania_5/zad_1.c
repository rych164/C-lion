#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node_t;

int addFirst(int new_val, node_t **head) {
    node_t *new = (node_t *) malloc(sizeof(node_t));
    if (new == NULL) {
        return 1;
    }
    new->val = new_val;
    new->next = *head;
    *head=new;
    return 0;
}
void printList(node_t * head)
{
    node_t * current=head;
    while(current!=NULL)
    {
        printf("%d\n",current->val);
        current=current->next;
    }
}
int main() {
    node_t *head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->val = 1;
    head->next = NULL;

    printList(head); // Print the list before adding a new node
    // Add a new node at the beginning of the list
    addFirst(3, &head);
    printf("%s","\nNew List\n");
    printList(head); // Print the list after adding the new node

    return 0;
}
//
// Created by wawrz on 25.03.2024.
//
