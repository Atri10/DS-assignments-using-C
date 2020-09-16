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
    //Starts from 0
    q->front = q->rear = 0;
    q->qarr = (int *)malloc(q->size * sizeof(int));
}

void EnQueue(struct Queue *q, int x)
{
    if((q->rear+1)%(q->size) == (q->front))
    {
        printf("Queue is full or Overflow\n");
    }
    else
    {
        q->rear = (q->rear+1)%(q->size);
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
        q->front= (q->front+1)%(q->size);
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
    int i = q.front+1;
    printf("******************\n");
    printf("******************\n");
    do
    {
         printf("%d  " , q.qarr[i]);
         i=(i+1)%q.size;
    }
    while(i!=(q.rear+1)%q.size);
}

int main()
{
    struct Queue q;
    int capacity = 5;

    creat(&q, capacity);
    EnQueue(&q,5);
    EnQueue(&q,8);
    DeQueue(&q);
      EnQueue(&q,8);
        EnQueue(&q,8);
        DeQueue(&q);
         EnQueue(&q,8);
          EnQueue(&q,8);
           EnQueue(&q,8);
             DeQueue(&q);
           printf(q->front);
           printf(q->rear);
    Display(q);
}