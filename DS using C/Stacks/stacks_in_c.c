#include"stdio.h"
#include"stdlib.h"
struct stacks
{
    int size;
    int top;
    int *stack;
};

void creat(struct stacks *st)
{
    printf("Enter size of the stack: ");
    scanf("%d" , &st->size);
    st-> top = -1;
    st->stack = (int *)malloc(st->size * sizeof(int));
}

void push(struct stacks *st , int x)
{
    if(st->top == st->size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->stack[st->top] = x;
    }
}

int pop(struct stacks *st)
{
    int x = -1;
    if(st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
       x = st->stack[st->top--];
    }
    return x;
}

void isEmpty(struct stacks *st)
{
    if(st->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack isn't Empty");
    }
}

void isFull(struct stacks *st)
{
    if(st->top == (st->size -1))
    {
        printf("Stack is Full\n");
    }
    else
    {
        printf("Stack isn't Full");
    }
}

int peek(struct stacks *st, int index)
{
    int x = -1;
    if(st->top-index+1<0)
    {
        printf("INDEX ISN't RIGHT\n");
       
    }
    else
    {
        x =  st->stack[st->top -  index + 1];
    }
    return x;
}

void display(struct stacks st)
{
    for(int i=st.top;i>=0;i--)
    {
        printf("%d\n" , st.stack[i]);
     
    }
}
int main()
{
   struct stacks st;
   creat(&st);
   push(&st, 6);
   push(&st, 2);
   push(&st, 4);
   push(&st, 9);
   
   display(st);

}