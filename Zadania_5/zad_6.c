#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int val;
    struct node *next;
} node_t;

void printList(node_t *head)
{
    node_t *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void addElementAtIndex(node_t **head, int index, int value)
{
    node_t *toInsert = (node_t *)malloc(sizeof(node_t));
    toInsert->val = value;
    toInsert->next = NULL;

    if (index == 0) {
        toInsert->next = *head;
        *head = toInsert;
        return;
    }

    node_t *current = *head;
    int i = 0;
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        free(toInsert);
        return;
    }

    toInsert->next = current->next;
    current->next = toInsert;
}


int main()
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->val = 0;
    head->next = (node_t *)malloc(sizeof(node_t));
    head->next->val = 1;
    head->next->next = (node_t *)malloc(sizeof(node_t));
    head->next->next->val = 2;
    head->next->next->next = NULL;

    printf("Original List:\n");
    printList(head);

    int value = 10;
    int index=0;
    addElementAtIndex(&head,index, value);

    printf("\nList after adding element with value %d and index %d:\n", value,index);
    printList(head);

    return 0;
}



//
// Created by wawrz on 26.03.2024.
//
//
// Created by wawrz on 26.03.2024.
//
