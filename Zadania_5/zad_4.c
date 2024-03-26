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

void removeByIndex(node_t **head, int index)
{
    if (*head == NULL)
        return;

    node_t *temp = *head;

    if (index == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // Find the node at position (index - 1)
    for (int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;

    // If the index is greater than the number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    node_t *next = temp->next->next;

    free(temp->next);

    temp->next = next;
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

    int index = 2; // Index of the node to be removed
    removeByIndex(&head, index);

    printf("\nList after removing element at index %d:\n", index);
    printList(head);

    return 0;
}
