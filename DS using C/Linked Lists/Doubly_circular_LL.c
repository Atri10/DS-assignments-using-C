#include "stdlib.h"
#include "stdio.h"

struct Node
{
    int data;
    struct Node *rear;
    struct Node *front;
}*first = NULL;


void insert_first(struct Node **head, int key)
{
    struct Node *p, *q, *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if((*head) == NULL)
    {
        (*head) = newNode;
        newNode->data = key;
        newNode->front = (*head);
        newNode->rear = (*head);

    } else{

        p = (*head);

        while (p->front != (*head))
        {
            p=p->front;
        }
        newNode->data = key;
        p->front = newNode;
        newNode->rear = p;
        newNode->front = (*head);
        (*head)->rear = newNode;
        (*head) = newNode;
    }
}

void insert_last(struct Node **head, int key)
{
    struct Node *p, *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if((*head) == NULL)
    {
        (*head) = newNode;
        newNode->data = key;
        newNode->front = (*head);
        newNode->rear = (*head);

    } else{

        p = (*head);

        while (p->front != (*head))
        {
            p = p->front;
        }
        newNode->data = key;
        p->front = newNode;
        newNode->rear = p;
        (*head)->rear = p;
        newNode->front = (*head);
    }

}

int Element_counter(struct Node *n)
{
    n = first;
    int i = 1;
    while(n->front != first)
    {
        n = n->front;
        i++;
    }
    return i;
}

void insert_after_position(struct Node **head, int position, int key)
{
    struct Node *p, *q, *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    int total = Element_counter(first);

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
        printf("\nPosition is greater than total elements");
    }
    else{

        p = (*head);
        int i = 0;

        while (i < position)
        {
            i++;
            q = p;
            p = p->front;
        }
        newNode->data = key;
        q->front = newNode;
        newNode->rear = q;
        newNode->front = p;
        p->rear = newNode;

    }
}


void Delete_first(struct Node **head)
{
    struct Node *p;

    if((*head) == NULL)
    {
        printf("\nList is Empty");
    }
    else if((*head)->front == (*head))
    {
        (*head) = NULL;
        free((*head));
    } else{

        p = (*head);

        while(p->front != (*head))
        {
            p = p->front;
        }

        p->front = (*head)->front;
        (*head)->front->rear = p;
        free((*head));
        (*head) = p->front;
    }
}


void Delete_last(struct Node **head)
{
    struct Node *p, *q;

    if((*head) == NULL)
    {
        printf("\nList is Empty");
    }
    else if((*head)->front == (*head))
    {
        (*head) = NULL;
        free((*head));
    } else{

        p = (*head);

        while (p->front != (*head))
        {
            q = p;
            p =p ->front;
        }

        q->front = (*head);
        (*head)->rear = q;
        free(p);
    }
}



void traverse(struct Node *n)
{

    n = first;
    while (n->front != first)
    {
        printf("\n%d", n->data);
        n = n->front;
    }

    printf("\n%d", n->data);
}

int main()
{
    insert_first(&first, 5);
    insert_first(&first, 50);
    insert_first(&first, 500);
    insert_last(&first,8);
    insert_last(&first,80);
    insert_last(&first,800);
  //  insert_after_position(&first, 2, 4);
    Delete_first(&first);
    Delete_last(&first);

    traverse(first);
}