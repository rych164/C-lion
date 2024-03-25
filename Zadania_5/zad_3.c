#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int val;
    struct node *next;
}node_t;

void printList(node_t *head)
{
    node_t *current=head;
    while(current!=NULL)
    {
        printf("%d\n",current->val);
        current=current->next;
    }
}

void removeLast(node_t * head)
{
    if(head==NULL ||head->next==NULL)
    {
        return;
    }
    while(head->next->next!=NULL)
    {
        head=head->next;
    }
    free(head->next);
    head->next=NULL;
}

int main()
{
    node_t *head=(node_t *) malloc(sizeof(node_t));
    head->val=0;
    head->next=(node_t *) malloc(sizeof(node_t));
    head->next->val=1;
    head->next->next=(node_t *) malloc(sizeof(node_t));
    head->next->next->val=2;
    head->next->next->next=NULL;
    printList(head);
    removeLast(head);
    printf("\nNew List\n");
    printList(head);
    return 0;
}
//
// Created by wawrz on 25.03.2024.
//
