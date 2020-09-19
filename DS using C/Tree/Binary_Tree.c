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
    newNode =(struct Node *) malloc(sizeof(struct Node));
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

void inorder_traverse(struct Node *n)
{
    if(n != NULL)
    {
        inorder_traverse(n->left);
        printf("\n%d" , n->data);
        inorder_traverse(n->right);
    }
}

int main()
{
    struct Node *root;
    root = newNode_creater(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);

    level_order(root);
    //inorder_traverse(root);
}