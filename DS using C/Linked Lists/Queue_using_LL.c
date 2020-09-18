#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

struct Node *front;
struct Node *rear;

void enQueue(struct Node *temp, int key)
{
   struct Node *newNode;
   newNode = (struct Node *)malloc(sizeof(struct Node));

   if (front == NULL)
   {
       front = newNode;
       rear = newNode;
       newNode->data = key;
       front->next = NULL;
       rear->next = NULL;
   } else{

       rear->next = newNode;
       newNode->data = key;
       rear = newNode;
       rear->next = NULL;
   }
}

void deQueue(struct Node *temp)
{
    if(front == NULL)
    {
        printf("\nUnder-Flow");
    } else {

        temp = front;
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct Node *p;
    if(front == NULL)
    {
        printf("\nQueue is Empty");
    } else{

        p = front;
        while (p != NULL)
        {
           printf("<-%d",p->data);
           p = p->next;
        }
    }
}


int main()
{
    enQueue(first, 5);
    enQueue(first, 6);
    enQueue(first, 7);
    enQueue(first, 8);
    deQueue(first);
    display();

}