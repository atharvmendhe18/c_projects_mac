#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *parent;
    struct node *left;
    struct node *right;
} node;

node *root = NULL;

void insert(int to_insert)
{
    node *n = malloc(sizeof(node));
    node *temp;
    node *parent_te;
    int i = 0;

    if (root == NULL)
    {
        n->number = to_insert;
        n->left = NULL;
        n->right = NULL;
        n->parent = n;
        root = n;
        printf("Went through the 1st wala insert condition\n");
    }
    else
    {
        temp = root;
        while (i == 0)
        {
            if (to_insert < temp->number)
            {
                parent_te = temp;
                temp = temp->left;
                printf("currently the parent is %i\n", parent_te->number);
                if (temp == NULL)
                {
                    n->number = to_insert;
                    n->left = NULL;
                    n->right = NULL;
                    n->parent = parent_te;
                    parent_te->left = n;
                    i = 1;
                    printf("Inserted %i and the parent is %i\n", to_insert, parent_te->number);
                }
            }
            else if (to_insert > temp->number)
            {
                parent_te = temp;
                temp = temp->right;
                if (temp == NULL)
                {
                    n->number = to_insert;
                    n->left = NULL;
                    n->right = NULL;
                    n->parent = parent_te;
                    parent_te->right = n;
                    i = 1;
                    printf("Inserted %i and the parent is %i\n", to_insert, parent_te->number);
                }
            }
        }
    }
}

void display_inorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    display_inorder(node->left);
    printf("%i\n", node->number);
    display_inorder(node->right);
}

// void delete(int to_delete)
// {
//     node *temp;
//     node *temp1 = NULL; // to store the node which needs to be deleted

//     int i = 0;
//     int og_num_for_case_4 = 0;

//     temp = root;
//     while (i == 0)
//     {
//         // ig i have to put this if condition before the whilel loop
//         // if (temp->number == to_delete)
//         // {
//         //     temp1 = temp;
//         //     i = 1;
//         // }
//         if (to_delete < temp->number)
//         {
//             temp = temp->left;
//             printf("currently the parent is %i\n", temp1->parent->number);
//             if (temp->number == to_delete)
//             {
//                 temp1 = temp;
//                 i = 1;
//                 // check if it is a leaf node or a node with one sided tree or a sub-tree underneath
//                 // in this i will be replacing with the deleted number with a number in the left side of the tree

//                 // if (temp->left == NULL && temp->right == NULL)
//                 // {
//                 //     parent->left = NULL;
//                 // }
//                 // else if (temp->left == NULL && temp->right != NULL)
//                 // {
//                 //     parent->right = temp->right;
//                 // }
//                 // else if (temp->left != NULL && temp->right == NULL)
//                 // {
//                 //     parent->left = temp->left;
//                 // }
//                 // else
//                 // {
//                 //     temp1 = temp->left;
//                 //     int highest_no = temp1->number;
//                 //     while (temp1->right != NULL)
//                 //     {
//                 //         parent1 = temp1;
//                 //         temp1 = temp1->right;
//                 //         highest_no = temp1->number;
//                 //     }
//                 //     temp->number = highest_no;
//                 //     if (temp1->right == NULL)
//                 //     {
//                 //         temp->left = temp1->left;
//                 //     }
//                 //     else if (parent1->right != NULL)
//                 //     {
//                 //         parent1->right = temp1->left;
//                 //     }
//                 // }

//                 // n->number = to_insert;
//                 // n->left = NULL;
//                 // n->right = NULL;
//                 // n->parent = temp;
//                 // parent->left = n;
//                 // i = 1;
//                 // printf("Inserted %i and the parent is %i\n", to_insert, parent->number);
//             }
//         }
//         else if (to_delete > temp->number)
//         {
//             temp = temp->right;
//             printf("currently the parent is %i\n", temp1->parent->number);
//             if (temp->number == to_delete)
//             {
//                 // check if it is a leaf node or a node with one sided tree or a sub-tree underneath
//                 // in this i will be replacing with the deleted number with a number in the left side of the tree
//                 temp1 = temp;
//                 i = 1;
//             }
//         }
//     }
//     printf("Yeh line ke phele error aa raha hai kya ?\n");
//     printf("To delete no is %i and parent is %i\n", temp1->number, temp1->parent->number);
//     int j = 2;
//     printf("Before entring while\n");
//     while (j == 2)
//     {
//         printf("%i\n", og_num_for_case_4);
//         printf("Going through while loop of delete\n");
//         if (temp1 == NULL)
//         {
//             printf("The value dosent exist in the tree");
//             j = 1;
//         }
//         // if (og_num_for_case_4 != 0)
//         // {
//         //     printf("Going through the og case wala condition\n");
//         //     if (temp1->number < og_num_for_case_4)
//         //     {
//         //         parent1->left = NULL;
//         //         j = 1;
//         //     }
//         //     else
//         //     {
//         //         parent1->right = NULL;
//         //         j = 1;
//         //     }
//         // }
//         else if (temp1->left == NULL && temp1->right == NULL)
//         {
//             printf("Went through the 1st wala conditon of delete\n");
//             if (temp1->number > temp1->parent->number)
//             {
//                 temp1->parent->right = NULL;
//             }
//             else
//             {
//                 temp1->parent->left = NULL;
//             }
//             j = 1;
//         }
//         else if (temp1->right == NULL)
//         {
//             printf("Went through the 2st wala conditon of delete\n");
//             temp1->parent->left = temp1->left;
//             j = 1;
//         }
//         else if (temp1->left == NULL)
//         {
//             printf("Went through the 2st wala conditon of delete\n");
//             temp1->parent->right = temp1->right;
//             j = 1;
//         }
//         else
//         {
//             // printf("Going through 4th codition\n");
//             // int largest_no;
//             // node *temp_largest_no = temp1->left;
//             // largest_no = temp_largest_no->number;
//             // // this while loop is not working(ok update, its workin now)
//             // while (temp_largest_no->right != NULL)
//             // {
//             //     temp_largest_no = temp_largest_no->right;
//             //     largest_no = temp_largest_no->number;
//             // }
//             // printf("The largest no in the left is %i\n", largest_no);
//             // printf("Changing temp1 ka number from %i to %i\n", temp1->number, largest_no);
//             // og_num_for_case_4 = temp1->number;
//             // temp1->number = largest_no;
//             // temp1 = temp_largest_no;
//             // parent1 = temp1->parent;
//             // printf("Ended 4th codition\n");
//         }
//     }
//     printf("Done with while\n");
// }

void delete(int to_delete)
{
    // there are total 4 cases, i will be putting them in a while loop

    node *temp;
    node *temp1;
    node *og_temp_delete;
    int i = 0;
    int largest_no;

    // first find the node we want to delete
    temp = root;
    if (temp->number == to_delete)
    {
        temp1 = temp;
        og_temp_delete = temp;
        i = 1;
    }
    while (i == 0)
    {
        printf("currently the parent is %i\n", temp->parent->number);
        if (to_delete < temp->number)
        {
            temp = temp->left;
            if (temp->number == to_delete)
            {
                temp1 = temp;
                og_temp_delete = temp;
                i = 1;
            }
        }
        else if (to_delete > temp->number)
        {
            temp = temp->right;
            if (temp->number == to_delete)
            {
                temp1 = temp;
                og_temp_delete = temp;
                i = 1;
            }
        }
    }
    printf("To delete number %i and parent is %i\n", temp1->number, temp1->parent->number);

    int j = 0;

    while (j == 0)
    {
        // case1
        if (temp1->left == NULL && temp1->right == NULL)
        {
            printf("Went through the 1st case\n");
            if (temp1->number > temp1->parent->number)
            {
                temp1->parent->right = NULL;
            }
            else
            {
                temp1->parent->left = NULL;
            }
            j = 1;
        }

        // case2
        else if (temp1->left == NULL)
        {
            printf("Went through the 2nd case\n");
            if (temp1->number > temp1->parent->number)
            {
                temp1->parent->right = temp1->right;
            }
            else
            {
                temp1->parent->left = temp1->right;
            }
            j = 1;
        }

        // case 3
        else if (temp1->right == NULL)
        {
            printf("Went through the 3rd case\n");
            if (temp1->number > temp1->parent->number)
            {
                temp1->parent->right = temp1->left;
            }
            else
            {
                temp1->parent->left = temp1->left;
            }
            j = 1;
        }

        // case 4
        else
        {
            // i am going through the left node and finding the largest number
            printf("Went through the 4th case\n");

            node *node_largest_no;

            largest_no = temp1->number;
            node_largest_no = temp1;
            while (node_largest_no->right != NULL)
            {
                node_largest_no = node_largest_no->right;
                largest_no = node_largest_no->number;
            }
            temp1 = node_largest_no;
            printf("The largest number in the left node of to delete node is %i\n", largest_no);
        }
    }
    og_temp_delete->number = largest_no;
}

int main(void)
{
    int j = 0;
    int user_in;
    while (j == 0)
    {
        int to_insert;
        int to_delete;
        printf(" Tree ka Menu \n");
        printf("[1] Insert\n[2] Dispay\n[3] Delete\n[4] Dispaly\n[5] Exit\n");
        printf("Enter Choice: ");
        scanf("%i", &user_in);
        switch (user_in)
        {
        case 1:
            printf("Enter a number to insert: ");
            scanf("%i", &to_insert);
            insert(to_insert);
            break;
        case 2:
            display_inorder(root);
            break;
        case 3:
            printf("Enter a number to delete: ");
            scanf("%i", &to_delete);
            delete (to_delete);
            break;
            // case 4:
            //     display();
            //     break;
            // case 5:
            //     exit_ll();
            //     printf("All Memory Freed");
            //     j = 1;
            //     break;
        }
    }
    return 0;
}
