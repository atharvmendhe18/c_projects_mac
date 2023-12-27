#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};

struct node *createnode(int data)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
struct node *insertNode(struct node *root, int val)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (val == root->data)
        {
            printf("cannot insert %d", val);
            return NULL;
        }
        else if (val < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
        struct node *to_insert = createnode(val);
        if (val < root->data)
        {
            prev->left = to_insert;
        }
        else
        {
            prev->right = to_insert;
        }
    }
}
int main()
{
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    insertNode(p, 16);
    printf("%d", p->right->right->data);
    return 0;
}
