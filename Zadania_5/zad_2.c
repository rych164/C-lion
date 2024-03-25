#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node_t;

void printList(node_t *head)
{
    node_t * current=head;
    while(current!=NULL)
    {
        printf("%d\n",current->val);
        current=current->next;
    }
}

int pop(node_t **head)
{
    if(*head==NULL)
    {
        return 1;
    }
    node_t *new_head=*head;
    *head=(*head)->next;
    free(new_head);
    return 0;
}

int main()
{
    node_t *head=NULL;
    head=(node_t *) malloc(sizeof(node_t));
    if(head==NULL)
    {
        return 1;
    }
    head->val=1;
    head->next=(node_t *) malloc(sizeof(node_t));
    head->next->val=2;
    head->next->next=NULL;

    printList(head);
    pop(&head);
    printf("%s","\nNew List\n");
    printList(head);
    return 0;
}
//
// Created by wawrz on 25.03.2024.
//
