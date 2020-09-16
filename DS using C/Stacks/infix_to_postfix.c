#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"ctype.h"
#define Size 100
char stack[Size];
int top = -1;
void push(char x)
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

char pop()
{
    char x;
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
    if(symb == '+' || symb == '-' || symb == '*' || symb == '/' || symb == '$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Precedence(char symb)
{
    if(symb == '^')
    {
        return 3;
    }
    else if(symb == '*' || symb == '/')
    {
        return 2;
    }
    else if(symb == '-' || symb == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infixtopostfix(char infix_exp[] , char postfix_exp[])
{
    int i,j;
    char x;
    char y;
    
    push('(');
    strcat(infix_exp, ")");
    i = 0;
    j = 0;
    x = infix_exp[i];
   

    while(x != '\0')
    {
        if(x == '(')
        {
          push(x);
        }
        else if( isdigit(x) || isalpha(x))
        {
           postfix_exp[j] = x;
           j++;
        }
        else if(IsOperator(x) == 1)
        {
            y = pop();
            while(IsOperator(y) == 1 && Precedence(y) >= Precedence(x))
            {
                postfix_exp[j] = y;
                j++;
                y = pop();
            }
            push(y);
            push(x);
        }
        else if (x == ')')
        {
            y = pop();
            while(y != '(')
            {
                postfix_exp[j] = y;
                j++;
                y = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n"); 
			getchar();
			exit(1);
        }
        i++;
        x = infix_exp[i];
    }
    if(top>0)
	{
		printf("\nInvalid infix Expression.\n");       
		getchar();
		exit(1);
	}

    postfix_exp[j] = '\0';

}

int main()
{
    char infix[Size], postfix[Size], prefix[Size];
    
    printf("\nEnter the expression: ");
    gets(infix);
    infixtopostfix(infix,postfix);
    printf("\nPostfix Expression: ");
    puts(postfix);

    return 0;
}