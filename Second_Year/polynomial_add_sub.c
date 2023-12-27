#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int constant;
    int power;
    struct node *next;
} node;

node *po1 = NULL;
node *po2 = NULL;
node *po3 = NULL;
void link(int c, int p);
void input()
{
    int j;
    int constant, power;
    printf("Enter the number of terms in PO1: ");
    scanf("%i", &j);
    for (int i = 0; i < j; i++)
    {
        node *n = malloc(sizeof(node));
        printf("Enter constant and then power: ");
        scanf("%i", &constant);
        scanf("%i", &power);
        if (po1 == NULL)
        {
            n->constant = constant;
            n->power = power;
            n->next = NULL;
            po1 = n;
        }
        else
        {
            node *temp;
            temp = po1;
            while (temp != NULL)
            {
                if (temp->next == NULL)
                {
                    n->constant = constant;
                    n->power = power;
                    temp->next = n;
                    n->next = NULL;
                    break;
                }
                temp = temp->next;
            }
        }
    }

    printf("Enter the number of terms in PO2: ");
    scanf("%i", &j);

    for (int i = 0; i < j; i++)
    {
        node *n = malloc(sizeof(node));
        printf("Enter constant and then power: ");
        scanf("%i", &constant);
        scanf("%i", &power);
        if (po2 == NULL)
        {
            n->constant = constant;
            n->power = power;
            n->next = NULL;
            po2 = n;
        }
        else
        {
            node *temp;
            printf("Going through else of the link fucntion\n");
            temp = po2;
            while (temp != NULL)
            {
                if (temp->next == NULL)
                {
                    n->constant = constant;
                    n->power = power;
                    temp->next = n;
                    n->next = NULL;
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void display(void)
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
            to_display_p = i->power;
            to_display_c = i->constant;
            printf("constant = %i power = %i \n", to_display_c, to_display_p);
            i = i->next;
        }
    }

    i = po2;
    if (i == NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        printf("Going through else\n");
        while (i != NULL)
        {
            to_display_p = i->power;
            to_display_c = i->constant;
            printf("constant = %i power = %i \n", to_display_c, to_display_p);
            i = i->next;
        }
    }
}

void add()
{
    node *temp1;
    node *temp2;
    temp1 = po1;
    temp2 = po2;
    int c, p;
    printf("In add fucn\n");
    while (temp1 != NULL && temp2 != NULL)
    {
        printf("Going through while of add\n");
        if (temp1->power == temp2->power)
        {
            c = temp1->constant + temp2->constant;
            link(c, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->power > temp2->power)
        {
            link(temp1->constant, temp1->power);
            temp1 = temp1->next;
        }
        else if (temp1->power < temp2->power)
        {
            link(temp2->constant, temp2->power);
            temp2 = temp2->next;
        }
    }

    if (temp1 == NULL)
    {
        while (temp2 != NULL)
        {
            link(temp2->constant, temp2->power);
            temp2 = temp2->next;
        }
    }

    if (temp2 == NULL)
    {
        while (temp1 != NULL)
        {
            link(temp1->constant, temp1->power);
            temp1 = temp1->next;
        }
    }
}

void subtract()
{
    node *temp1;
    node *temp2;
    temp1 = po1;
    temp2 = po2;
    int c, p;
    printf("In add fucn\n");
    while (temp1 != NULL && temp2 != NULL)
    {
        printf("Going through while of add\n");
        if (temp1->power == temp2->power)
        {
            c = temp1->constant - temp2->constant;
            link(c, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->power > temp2->power)
        {
            link(temp1->constant, temp1->power);
            temp1 = temp1->next;
        }
        else if (temp1->power < temp2->power)
        {
            c = temp2->constant * -1;
            link(c, temp2->power);
            temp2 = temp2->next;
        }
    }

    if (temp1 == NULL)
    {
        while (temp2 != NULL)
        {
            c = temp2->constant * -1;
            link(c, temp2->power);
            temp2 = temp2->next;
        }
    }

    if (temp2 == NULL)
    {
        while (temp1 != NULL)
        {
            link(temp1->constant, temp1->power);
            temp1 = temp1->next;
        }
    }
}

void link(int c, int p)
{
    node *n = malloc(sizeof(node));
    if (po3 == NULL)
    {
        printf("Going through if of link\n");
        n->constant = c;
        n->power = p;
        n->next = NULL;
        po3 = n;
    }
    else
    {
        printf("Going through else of link\n");
        node *temp;
        temp = po3;
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

void display_ans(void)
{
    node *i;
    int to_display_c;
    int to_display_p;
    i = po3;
    if (i == NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        printf("Going through else\n");
        while (i != NULL)
        {
            to_display_p = i->power;
            to_display_c = i->constant;
            printf("constant = %i power = %i \n", to_display_c, to_display_p);
            i = i->next;
        }
    }
}
int main()
{
    input();
    display();
    add();
    printf("\n");
    display_ans();
}