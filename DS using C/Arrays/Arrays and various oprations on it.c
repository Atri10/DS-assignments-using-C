#include"stdio.h"
void printer(int a[], int b);
int searcher(int a[],int n,int key);
void inserter(int a[],int b,int index,int key);
void replacer(int a[], int b, int old, int new);
void deleter(int a[],int b,int key);


int main(void)
{
    int n,opr,find,new_el,idx,old_el;
    printf("Enter array size: ");
    scanf("%d", &n);
    int testarray[n];
     printf("\n");
    printf("Enter the first elemnt of araay and press enter, continue this\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d" , &testarray[i]);
    }
    printf("\n\n");
    printf("what kind of operation you want to perform?\n\n Press 1 to Print Array\n Press 2 to search an element\n Press 3 to insert an Element\n Press 4 to replace an element\n Press 5 to delete an element\n");
    scanf("%d", &opr);
     printf("\n\n");
    
    switch(opr)
    {
        case 1:
            printf("\n");
            printer(testarray, n);
            break;

        case 2:
           printf("\n");
           printf("Enter element you want to search: ");
           scanf("%d", &find); 
           searcher(testarray, n, find);  
           break;
         
        case 3:
           printf("\n");
           printf("Enter element you want to insert: ");
           scanf("%d", &new_el);
           printf("\n");
           printf("Enter index at which you want to insert element: ");
           scanf("%d", &idx);
           inserter(testarray,n,idx,new_el);
           break;

        case 4:
           printf("\n");
           printf("Enter element you want to replace: ");
           scanf("%d", &old_el);
            printf("\n");
           printf("Enter new element which will replace previous: ");
           scanf("%d", &new_el);
           replacer(testarray,n,old_el,new_el);   
           break;

        case 5:
           printf("\n");
           printf("Enter element you want to delete: ");
           scanf("%d", &old_el);
           deleter(testarray,n,old_el);
           break;
    } 
    
}

void printer(int a[], int b)
{
    printf("\n\n\n");
    printf("Printing arrays now\n\n");
    for(int i=0;i<b;i++)
    {
        printf("%d\n" , a[i]);
    }

     printf("\n\n\n");
     printf("***********************");
}

int searcher(int a[],int n,int key)
{
    int stat = 0;
    int idx,i;
    printf("\n\n\n");
    printf("Searching arrays now\n");
     printf("\n");
      printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i] == key)
        {
               stat= 1 ;
               idx = i;
               break;       
        }
    }

    if(stat == 1)
    {
        printf("Elemnt %d is at indext = %d" , key,idx);
    }
    else
    {
        printf("No elemnt found");
    }
}

void inserter(int a[],int b,int index,int key)
{
      
    int newarr[b+1];
    int i,j;

    for(i=0;i<b+1;i++)
    {
       if(i<index)
       {
          newarr[i] = a[i];
       }
       else if(i == index)
       {
          newarr[i] = key ;
       }
       else if(i>index)
       {
           newarr[i] = a[i-1];
       }
      
    }
    printer(newarr, b+1);
}

void replacer(int a[], int b, int old, int new)
{
    searcher(a,b,old);
    printf("\n\n\n");
    printf("Replacing %d with %d now" ,old, new);
    for(int i=0;i<b;i++)
    {
       if(a[i] == old)
       {
           a[i] = new;
       }
    }
    printer(a,b);
}

void deleter(int a[],int b,int key)
{
     int na[b-1];
     int idx;
     searcher(a,b,key);
     printf("\n\n\n");
    printf("Deleting %d now" ,key);
     for(int i=0;i<b;i++)
     {  
        if(a[i] == key)
        {
               idx = i;
               break;       
        }
     }

     for(int i=0;i<b-1;i++)
     {
         if(i<idx)
         {
             na[i]= a[i];
         }
         else
         {
             na[i]= a[i+1];
         }
     }
     
     printer(na, b-1);
}