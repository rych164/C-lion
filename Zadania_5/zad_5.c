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

void removeByValue(node_t **head, int value)
{
    if (*head == NULL)
        return;

    node_t *temp = *head;

    if (value == temp->val)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    node_t *current = temp;
    while (current->next != NULL)
    {
        if (value == current->next->val)
        {
            temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }


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

    int value = 0; // Index of the node to be removed
    removeByValue(&head, value);

    printf("\nList after removing element with value %d:\n", value);
    printList(head);

    return 0;
}



//
// Created by wawrz on 26.03.2024.
//
