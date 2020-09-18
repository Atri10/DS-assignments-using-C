#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void push(struct Node **top, int key)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if((*top) == NULL)
    {
        newNode->data = key;
        newNode->next = NULL;
        (*top) = newNode;
    }
    else if(newNode == NULL)
    {
        printf("\nMemory Error unable to push the data");
    } else{

        newNode->data = key;
        newNode->next = (*top);
        (*top) = newNode;
    }
}

void pop(struct Node **top)
{

    struct Node *temp;
    int key;

    if((*top) == NULL)
    {
        printf("\nStack UNDER-flow");
    }
    else{
        key = (*top)->data;
        temp = (*top);
        (*top) = (*top)->next;
        free(temp);
    }
}

void peek(struct Node **top)
{
    printf("\n%d" , (*top)->data);
}

void display(struct Node **top)
{
    struct Node *temp;
    temp = (*top);

    if((temp) == NULL)
    {
        printf("\nStack is Empty");
    }
    else{
        while (temp != NULL)
        {
            printf("\n| ");
            printf("%d", temp->data);
            printf(" |\n");
            printf("-------");
            temp = temp->next;
        }
    }
}

int main()
{
    push(&first, 5);
    push(&first, 50);
    push(&first, 500);
    push(&first, 5000);
    pop(&first);
    pop(&first);
    pop(&first);
    pop(&first);
    pop(&first);
    display(&first);
}