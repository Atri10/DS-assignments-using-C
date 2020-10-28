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
        printf("\nKey Found in the BST\n");
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
        printf(" %d ", root->data);
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
        printf(" %d " ,n->data);
        preOrder_traverse(n->left);
        preOrder_traverse(n->right);
    }
}

void inorder_traverse(struct Node *n)
{
    if(n != NULL)
    {
        inorder_traverse(n->left);
        printf(" %d " , n->data);
        inorder_traverse(n->right);
    }
}

void postOrder_traverse(struct Node *n)
{
    if( n != NULL)
    {
        postOrder_traverse(n->left);
        postOrder_traverse(n->right);
        printf(" %d ", n->data);
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

    int rootelm, choice = 0, num;
    struct Node *root = NULL;
    printf("\nEnter the Root Node first: ");
    scanf("%d", &rootelm);

    root = insert(root,rootelm);
    printf("\n\nWelcome, Please Enter The choice of Operation You want to Perform on the Binary search Tree having root %d",rootelm);

    while (choice != 9)
    {
        printf("\n\n=> Press 1 to Insert a new Element");
        printf("\n=>Press 2 to Print the Pre-order Traversal");
        printf("\n=>Press 3 to Print the In-order Traversal");
        printf("\n=>Press 4 to Print the Post-order Traversal");
        printf("\n=>Press 5 to Print the Level-order Traversal");
        printf("\n=>Press 6 to get the Height of the Binary search Tree");
        printf("\n=>Press 7 to Search an Element in the Binary search Tree");
        printf("\n=>Press 8 to Delete an Element in the Binary Search Tree");
        printf("\n=>Press 9 to Exit the Program\n\n");

        scanf("%d" , &choice);

        switch (choice)
        {
            case 1:
                printf("\n\nEnter the Element you want to insert: ");
                scanf("%d" ,&num);
                insert(root, num);
                break;

            case 2:
                printf("\n\nPre-order Traversal is: \n");
                preOrder_traverse(root);
                break;

            case 3:
                printf("\n\nIn-order Traversal is: \n");
                inorder_traverse(root);
                break;

            case 4:
                printf("\n\nPost-order Traversal is: \n");
                postOrder_traverse(root);
                break;

            case 5:
                printf("\n\nLevel-order Traversal is: \n");
                level_order(root);
                break;

            case 6:
                num = height(root);
                printf("\n\nHeight of the Binary Search Tree is: %d" ,num);
                break;

            case 7:
                printf("\n\nEnter the Element you want to Search in BST: ");
                scanf("%d" , &num);
                search_in_BT(root, num);
                break;

            case 8:
                printf("\n\nEnter the Element you want to Delete: ");
                scanf("%d" , &num);
                Delete(root, num);
                break;

            case 9:
                printf("\nClosing the Program Now\n");
                break;
        }
    }
}
