#include"stdio.h"
#include"ctype.h"
#include"string.h"
#include"stdlib.h"

#define Size 50

char stack[Size];
int top = -1;

void push(int x)
{
    if(top >= Size-1)
    {
        printf("\nStack overflow");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop()
{
    int x = -1;
    if(top < 0)
    {
        printf("\nStack Underflow");
        getchar();
        exit(1);
    }
    else
    {
        x = stack[top];
        top--;
        return(x);
    }
   
}

int IsOperator(char symb)
{
    if(symb == '+' || symb == '-' || symb == '*' || symb == '/' || symb == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void evelutor(char postfix_exp[])
{
   int i = 0;
   char exp;
   int digit,x,y,z;

   exp = postfix_exp[i];

   while(exp != '\0')
   {
       if(isdigit(exp))
       {
          digit = exp - 48;
          push(digit);
       }
       else if(IsOperator(exp) == 1)
       {
         x = pop();
         y= pop();

         switch(exp)
         {
             case '+':
             {
                 z = x + y;
                 break;
             }
             case '-':
             {
                 z = y - x;
                   break;
             }
             case '/':
             {
                 z = x / y;
                   break;
             }
             case '*':
             {
                 z = x * y;
                   break;
             }
          }
          push(z);
       }
       i++;
       exp = postfix_exp[i];
   }

}

int main()
{
    char postfix[Size];
    printf("\nEnter the expression: ");
    gets(postfix);
    evelutor(postfix);
    printf("\nResult is %d" , pop());
    printf("\n**************");
}