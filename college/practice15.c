// Design a structure named employee to print names and nos. of employee who have 5 years or more
// experience and salary less than Rs. 10,000 using array of structure (Name, Experience and Salary as member)

#include <stdio.h>

struct employee
{
    char name[20];
    int salary;
    int experience;
};

int main(void)
{
    struct employee employee[5];

    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter the name of the %ist employee: ", i + 1);
        scanf("%s", employee[i].name);
        printf("\nEnter the employee's experience(in years): ");
        scanf("%i", &employee[i].experience);
        printf("\nEnter the employee's salary: ");
        scanf("%i", &employee[i].salary);
    }

    int no_of_emp = 0;

    for (int i = 0; i < 5; i++)
    {
        if (employee[i].salary < 10000 && employee[i].experience >= 5)
        {
            printf("Name of employee: %s\n", employee[i].name);
            no_of_emp++;
        }
    }
}