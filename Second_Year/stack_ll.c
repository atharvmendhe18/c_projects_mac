#include <stdio.h>
#include <stdlib.h>

void display(void);
typedef struct node
{
    int number;
    struct node *next;
} node;

node *list;

void create()
{
    display();
    list = NULL;
}

void push(int to_insert)
{
    node *n = malloc(sizeof(node));
    node *temp;
    temp = list;
    if (temp == NULL)
    {
        n->number = to_insert;
        n->next = NULL;
        list = n;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                n->number = to_insert;
                n->next = NULL;
                temp->next = n;
                break;
            }
            temp = temp->next;
        }
    }
}

void pop()
{
    node *temp, *pre;
    temp = list;

    if (temp == NULL)
    {
        printf("Empty Stack");
    }
    else if (temp->next == NULL)
    {
        list = NULL;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                pre->next = NULL;
                break;
            }
            pre = temp;
            temp = temp->next;
        }
    }
}

// void insert_after(int to_insert)
// {
//     int to_insert_after;
//     node *n = malloc(sizeof(node));
//     if (list == NULL)
//     {
//         n->number = to_insert;
//         n->next = NULL;
//         list = n;
//     }
//     else
//     {
//         node *temp;
//         node *i;
//         i = list;
//         printf("Enter the number to insert after: ");
//         scanf("%i", &to_insert_after);
//         printf("\n");
//         while (i != NULL)
//         {
//             if (i->number == to_insert_after)
//             {
//                 temp = i->next;
//                 i->next = n;
//                 n->number = to_insert;
//                 n->next = temp;
//             }
//             i = i->next;
//         }
//     }
// }

// void insert_before(int to_insert)
// {
//     int to_insert_before;
//     node *temp;
//     node *n = malloc(sizeof(node));
//     printf("Enter the number to insert before: ");
//     scanf("%i", &to_insert_before);
//     printf("\n");
//     if (list == NULL)
//     {
//         printf("Empty List\n");
//     }
//     else if (to_insert_before == list->number)
//     {
//         temp = list;
//         list = n;
//         n->number = to_insert;
//         n->next = temp;
//     }
//     else
//     {
//         node *i;
//         i = list;
//         while (i != NULL)
//         {
//             if (i->number == to_insert_before)
//             {
//                 temp->next = n;
//                 n->number = to_insert;
//                 n->next = i;
//                 break;
//             }
//             temp = i;
//             i = i->next;
//         }
//     }
// }

void display(void)
{
    node *i;
    int to_display;
    i = list;
    if (i == NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        printf("Going through else\n");
        while (i != NULL)
        {
            to_display = i->number;
            printf("%i\n", to_display);
            i = i->next;
        }
    }
}

void exit_ll(void)
{
    node *i;
    i = list;
    node *temp;
    while (i != NULL)
    {
        temp = i->next;
        free(i);
        i = temp;
    }
}

// void delete(int to_delete)
// {
//     node *temp;
//     node *pre;
//     temp = list;
//     while (temp != NULL)
//     {
//         if (temp->next == NULL && temp->number == to_delete)
//         {
//             pre->next = NULL;
//             free(temp);
//         }
//         else if (to_delete == list->number)
//         {
//             list = temp->next;
//             free(temp);
//         }
//         else if (to_delete == temp->number)
//         {
//             pre->next = temp->next;
//             free(temp);
//         }
//         pre = temp;
//         temp = temp->next;
//     }
// }

int main(void)
{
    int j = 0;
    int user_in;
    while (j == 0)
    {
        int to_insert;
        printf(" Queue using Linked List Menu\n");
        printf("[1] Create\n[2] Push\n[3] Pop\n[4] Dispaly\n[5] Exit\n");
        printf("Enter Choice: ");
        scanf("%i", &user_in);
        switch (user_in)
        {
        case 1:
            create();
            break;
        case 2:
            printf("Enter a number to insert: ");
            scanf("%i", &to_insert);
            push(to_insert);
            break;
        case 3:
            pop();
            break;
        case 4:
            display();
            break;
        case 5:
            exit_ll();
            printf("All Memory Freed");
            j = 1;
            break;
        }
    }
    return 0;
}
