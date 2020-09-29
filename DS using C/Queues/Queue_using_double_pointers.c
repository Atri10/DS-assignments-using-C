#include"stdio.h"
#include"stdlib.h"
struct Queue
{
    int size,front,rear;
    int *qarr;
};

void creat(struct Queue *q, int x)
{
    q->size = x;
    q->front = q->rear = -1;
    q->qarr = (int *)malloc(q->size * sizeof(int));
}

void EnQueue(struct Queue *q, int x)
{
    if(q->rear == (q->size-1))
    {
        printf("Queue is full or Overflow\n");
    }
    else
    {
        q->rear++;
        q->qarr[q->rear] = x;
    }
}

int DeQueue(struct Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
    {
        printf("Queue is Empty or Queue Underflow\n");
    }
    else
    {
        q->front++;
        x = q->qarr[q->front];
    }
    return x;
}

int Front(struct Queue *q)
{
    return q->qarr[q->rear];
}

int Queuesize(struct Queue *q)
{
    return (q->rear - q->front);
}

void Display(struct Queue q)
{
    int i;
    printf("******************\n");
    printf("******************\n");
    for(i=q.rear; i>=q.front+1;i--)
    {
        printf("%d  " , q.qarr[i]);
    }
}

int main()
{
    struct Queue q;
    int capacity = 10;

    creat(&q, capacity);
    EnQueue(&q,5);
    EnQueue(&q,8);
    EnQueue(&q,3);
    EnQueue(&q,9);
    DeQueue(&q);
    printf("Quesize is: %d\n" ,Queuesize(&q));
    Display(q);
}