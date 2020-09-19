#include "stdio.h"
#include "stdlib.h"

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node *newNode_creater(int key)
{
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int key)
{
    if(root == NULL)
    {
        return newNode_creater(key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->left = insert(root->left, key);
    }

    return root;
}

int height(struct Node *root)
{
    if(root == NULL)
    {
        return 0;
    } else{

        int LH = height(root->left);
        int RH = height(root->right);

        if(LH > RH)
        {
            return (LH+1);
        } else{
            return (RH+1);
        }
    }
}

void print_current_level(struct Node *root, int level)
{
    if(root == NULL)
    {
        return;
    }

    if(level == 1)
    {
        printf("\n%d", root->data);
    }
    else if(level > 1)
    {
        print_current_level(root->left, level-1);
        print_current_level(root->right, level-1);
    }
}
void level_order(struct Node *root)
{
    int H = height(root), i;

    for(i=1;i<=H;i++)
    {
        print_current_level(root, i);
    }
}

void preOrder_traverse(struct Node *n)
{
    if(n != NULL)
    {
        printf("\n%d" ,n->data);
        preOrder_traverse(n->left);
        preOrder_traverse(n->right);
    }
}

void inorder_traverse(struct Node *n)
{
    if(n != NULL)
    {
        inorder_traverse(n->left);
        printf("\n%d" , n->data);
        inorder_traverse(n->right);
    }
}

void postOrder_traverse(struct Node *n)
{
    if( n != NULL)
    {
        postOrder_traverse(n->left);
        postOrder_traverse(n->right);
        printf("\n%d", n->data);
    }
}

int main()
{
    struct Node *root;
    root = newNode_creater(1);

    insert(root,2);
    insert(root,4);
    insert(root,5);
    insert(root,3);
    insert(root,6);
    insert(root,7);

    printf("%d", height(root));

   // preOrder_traverse(root);
   // inorder_traverse(root);
  //  postOrder_traverse(root);
  //  level_order(root);
}
