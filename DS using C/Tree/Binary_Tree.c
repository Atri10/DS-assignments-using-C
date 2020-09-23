#include "stdio.h"
#include "stdlib.h"

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

void search_in_BT(struct Node *root, int key)
{
    if(root->data == key)
    {
        printf("\nKey Exists\n");
        return;
    } else if (root->left == NULL && root->right == NULL)
    {
        printf("\nKey not found\n");
    }
    else if(key > root->data)
    {
        search_in_BT(root->right, key);
    } else if( key < root->data)
    {
        search_in_BT(root->left, key);
    }
}

struct Node *insert(struct Node *root, int key)
{
    if(root == NULL)
    {
        struct Node *newNode;
        newNode = malloc(sizeof(struct Node));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
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

struct Node *inpre(struct Node *n)
{
    while (n && n->right != NULL)
    {
        n = n->right;
    }
    return n;
}

struct Node *insucc(struct Node *n)
{
    while (n && n->left != NULL)
    {
        n = n->left;
    }
    return n;
}

struct Node *Delete(struct Node *n, int key)
{
    struct Node *p;
    if (n == NULL)
    {
        printf("Tree is Empty");
        return NULL;
    }
    else if(n->right == NULL && n->left == NULL)
    {

        free(n);
        return NULL;
    }

    if (key < n->data)
    {
        n->left = Delete(n->left, key);
    }
    else if(key > n->data)
    {
        n->right =  Delete(n->right, key);
    } else{

        if (height(n->left) > height(n->right))
        {
            p = inpre(n->left);
            n->data = p->data;
            n->left = Delete(n->left, p->data);
        } else{
            p = insucc(n->right);
            n->data = p->data;
            n->right = Delete(n->right, p->data);
        }
    }
}


int main()
{

    struct Node *root = NULL;

    root = insert(root,5);
    int arr[] = {2,45,30,10,25};

    for(int i=0; i<5 ;i++)
    {
        insert(root,arr[i]);
    }

    Delete(root, 10);
    search_in_BT(root, 10);


    //printf("%d", height(root));

    // preOrder_traverse(root);
    // inorder_traverse(root);
    //  postOrder_traverse(root);
    //  level_order(root);
}
