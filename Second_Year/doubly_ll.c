#include <stdio.h>
#include <stdlib.h>

void display(void);
typedef struct node
{
    int number;
    struct node *next;
    struct node *preious;
} node;

node *list;

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

void create()
{
    display();
    list = NULL;
}

void insert_after(int to_insert)
{
    node *temp;
    node *i;
    node *n = malloc(sizeof(node));
    int to_insert_after;

    if (list == NULL)
    {
        printf("Since list is empty inserting the 1st element\n");
        list = n;
        n->number = to_insert;
        n->next = NULL;
    }
    else
    {
        printf("Enter the no to insert after: ");
        scanf("%i", &to_insert_after);
        temp = list;
        while (temp != NULL)
        {
            printf("Going toroghjt while\n");
            if (temp->next == NULL)
            {
                temp->next = n;
                n->preious = temp;
                n->number = to_insert;
                n->next = NULL;
            }
            else if (temp->number == to_insert_after)
            {
                i = temp->next;
                temp->next = n;
                n->next = i;
                n->preious = temp;
                i->preious = n;
                n->number = to_insert;
                break;
            }
            temp = temp->next;
        }
    }
}

int main(void)
{
    int j = 0;
    int user_in;
    while (j == 0)
    {
        int to_insert;
        printf("Linked List Menu\n");
        printf("[1] Create\n[2] Insert After\n[3] Insert Before\n[4] Delete\n[5] Display\n[6] Exit\n");
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
            insert_after(to_insert);
            break;
        case 3:
            // printf("Enter a number to insert: ");
            // scanf("%i", &to_insert);
            // insert_before(to_insert);
            break;
        case 4:
            // printf("Enter a number to delete: ");
            // scanf("%i", &to_insert);
            // delete (to_insert);
            break;
        case 5:
            display();
            break;
        case 6:
            // exit_ll();
            // printf("All Memory Freed");
            j = 1;
            break;
        }
    }
    return 0;
}