#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
}*first = NULL;


void insertion(struct NODE **first, int possition, int key)
{
    struct NODE *temp, *p, *q;

    temp = (struct NODE *)malloc(sizeof(struct NODE));


    if(possition == 1)
    {
        p = *first;
        temp->data = key;
        temp->next = p;
        *first = temp;
    }
    else
    {
        int i=0;
        p = *first;
        while ((p != NULL) && (i < possition))
        {
            i++;
            q = p;
            p = p->next;
        }
        q->next = temp;
        temp->data=key;
        temp->next = p;
    }

}


void deletion(struct NODE **first, int possition)
{
    struct NODE *p,*q;
    p = *first;

    if(possition == 1)
    {
        *first = (*first)->next;
        free(p);
    }
    else
    {
        int i=1;
        while ((p != NULL) && (i<possition))
        {
            i++;
            q = p;
            p = p->next;
        }

        if (p==NULL)
        {
            printf("\nNO Postion exists.");
        }
        else{
            q->next = p->next;
            free(p);
        }
    }
}

void search(struct NODE *n, int key)
{
    int i=1,j;
    int temp = 0;
    while (n != NULL)
    {
        if(n->data == key)
        {
            temp = 1;
            j = i;
        }
        n = n->next;
        i++;
    }

    if(temp == 1)
    {
        printf("\nElemnt found at position %d ", j);
    } else{
        printf("\nElement doesn't exist in the Linked list");
    }


}


void Traverse(struct NODE *n)
{
    while(n != NULL)
    {
        printf("\n%d", n->data);
        n = n->next;
    }
}


int main()
{
    insertion(&first , 1 ,4);
    insertion(&first , 2 ,40);
    insertion(&first , 3 ,400);
    insertion(&first , 4 ,4000);
    
    deletion(&first,1);

    Traverse(first);

    search(first, 4);
}
