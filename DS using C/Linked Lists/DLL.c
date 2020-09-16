#include "stdlib.h"
#include "stdio.h"

struct Node
{
    struct Node *front;
    int data;
    struct Node *rear;
}*first = NULL;

void insertion(struct Node **head, int position, int key)
{
    struct Node *newNode, *p;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // First time when we insert at position 1 head wil be Null
    if(((*head) == NULL) && position == 1)
    {
        newNode->data = key;
        newNode->rear = NULL;
        newNode->front = NULL;
        *head = newNode;
    }
    // To modify and change the head
    else if(((*head) != NULL) && position == 1)
    {
        newNode->data = key;
        newNode->front = *head;
        newNode->rear = NULL;
        (*head)->rear = newNode;
        (*head) = newNode;
    } else{
        // For any position which is less than total number of elements is LL
        p = (*head);

        for(int i=1; i< position-1; i++)
        {
            p = p->front;
            if(p == NULL)
            {
                printf("\nLink List limit exceeded\nLess element are in list than position.");
            }
        }

        newNode->data = key;
        newNode->front = p->front;
        newNode->rear = p;
        p->front = newNode;
        p->front->rear = newNode;

    }

}

void search(struct Node *n, int key) {
    int i = 1, j;
    int temp = 0;
    while (n != NULL)
    {
        if (n->data == key) {
            temp = 1;
            j = i;
        }
        n = n->front;
        i++;
    }
    if(temp == 1)
    {
        printf("\nElemnt found at position %d ", j);
    } else{
        printf("\nElement doesn't exist in the Linked list");
    }

}

void Traverse(struct Node *n)
{
    while(n != NULL)
    {
        printf("\n%d", n->data);
        n = n->front;
    }
}


int main()
{
    insertion(&first, 1, 5);
    insertion(&first, 2, 50);
    insertion(&first, 3, 500);
    insertion(&first, 4, 5000);

    search(first, 500);
    Traverse(first);
}
