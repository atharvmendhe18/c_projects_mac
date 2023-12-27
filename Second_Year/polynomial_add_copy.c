#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int constant;
    int power;
    struct node *next;
} node;

void display(node *po);
// void input(node &po);
void link(int &po);

node *po1 = NULL;
node *po2 = NULL;
node *po3 = NULL;

int main()
{
    printf("\nPlease enter the details of the first polonymal:  ");
    link(&po1);
    // printf("%i", po1->constant);
    display(po1);
}

void link(int &po)
{
    node *n = malloc(sizeof(node));
    if (*po == NULL)
    {
        int c, p;
        printf("Enter the constant: ");
        scanf("%i", &c);
        printf("\nEnter the power: ");
        scanf("%i", &p);
        printf("\n");
        printf("Going through while of the link fucntion\n");
        n->constant = c;
        n->power = p;
        n->next = NULL;
        printf("%i %i\n", n->constant, n->power);
        *po = n;
    }
    else
    {
        node *temp;
        printf("Going through else of the link fucntion\n");
        temp = *po;
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                n->constant = c;
                n->power = p;
                temp->next = n;
                n->next = NULL;
                break;
            }
            temp = temp->next;
        }
    }
}

void add(int p, int c)
{
}

// void input(node &po)
// {
//     int c, p;
//     printf("Enter the constant: ");
//     scanf("%i", &c);
//     printf("\nEnter the power: ");
//     scanf("%i", &p);
//     printf("\n");
//     link(*po, p, c);
// }

void display(node *po)
{
    node *i;
    int to_display_c;
    int to_display_p;
    i = po1;
    if (i == NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        printf("Going through else\n");
        while (i != NULL)
        {
            to_display_c = i->constant;
            to_display_p = i->power;
            printf("Constant = %i Power = %i", to_display_c, to_display_p);
            i = i->next;
        }
    }
}