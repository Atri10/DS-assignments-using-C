#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void insert_beginning(struct Node **head, int key)
{
    struct Node *p, *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("\nOVERFLOW\nMemory-Error");
    }
    else if((*head) == NULL)
    {

        (*head) = newNode;
        newNode->data = key;
        newNode->next = (*head);

    } else{

        p = (*head);

        while (p->next != (*head))
        {
            p=p->next;
        }
        newNode->next = (*head);
        newNode->data = key;
        p->next  = newNode;
        (*head) = newNode;

    }
}


void insert_at_last(struct Node **head, int key)
{
    struct Node *p, *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    if((*head) == NULL)
    {
        printf("\nList is Empty");
    }
    else if(newNode == NULL)
    {
        printf("\nOVERFLOW\nMemory-Error");
    }else{

        p = (*head);

        while (p->next != (*head))
        {
            p=p->next;
        }

        p->next = newNode;
        newNode->next = (*head);
    }
}

int Element_counter(struct Node *n)
{
    n = first;
    int i = 1;
    while(n->next != first)
    {
        n = n->next;
        i++;
    }
    return i;
}


void insert_after_position(struct Node **head, int position, int key)
{
    int total = Element_counter(first);
    struct Node *p, *q, *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    if((*head) == NULL)
    {
        printf("\nList is Empty");
    }
    else if(newNode == NULL)
    {
        printf("\nOVERFLOW\nMemory-Error");
    }
    else if(position > total)
    {
        printf("\nIndex is greater than total elements");
    } else{

        p = (*head);
        int i = 0;

        while(i<position)
        {
            i++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
    }

}


void Delete_first(struct Node **head)
{
    struct Node *p;

    if((*head) == NULL)
    {
        printf("\nList is Empty");
    }
    else if((*head)->next == (*head))
    {
        (*head) = NULL;
        free((*head));
    } else{

        p = (*head);

        while (p->next != (*head))
        {
            p= p->next;
        }

        p->next = (*head)->next;
        free((*head));
        (*head) = p->next;
    }

}


void Delete_last(struct Node **head)
{
    struct Node *p,*q;

    if((*head) == NULL)
    {
        printf("\nList is Empty");
    }
    else if((*head)->next == (*head))
    {
        (*head) = NULL;
        free((*head));
    } else{

        p = (*head);

        while (p->next != (*head))
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        free(p);

    }
}


void Delete_after_position(struct Node **head, int position)
{
    struct Node *p,*q;

    if((*head) == NULL)
    {
        printf("\nList is Empty");
    }
    else if((*head)->next == (*head))
    {
        (*head) = NULL;
        free((*head));
    } else{

        p = (*head);
        int i = 0;

        while(i<position)
        {
            i++;
            q = p;
            p = p->next;
        }

        q->next = p->next;
        free(p);

    }
}

void Traverse(struct Node *n)
{
    n = first;

    while(n->next != first)
    {
        printf("\n%d", n->data);
        n = n->next;
    }
    printf("\n%d", n -> data);
}

int main()
{
    insert_beginning(&first, 5);
    insert_beginning(&first, 50);
    insert_beginning(&first, 500);
    insert_at_last(&first, 8);
    insert_at_last(&first, 80);
    insert_at_last(&first, 800);



    printf("\nInserting 7 at position 3rd\n");
    insert_after_position(&first,2,7);


    printf("\nBefore DELETION\n");
    Traverse(first);


    Delete_first(&first);
    Delete_last(&first);
    Delete_after_position(&first,1);


    printf("\n\nAfter DELETION\n");
    Traverse(first);
}