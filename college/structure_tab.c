// WAP t store and display the name, marks in three subjects an roll number of ‘n’ students using structure. Display the output in tabular form.

#include <stdio.h>

struct student
{
    char name[10];
    int roll_no;
    int marks_math;
    int marks_physics;
    int marks_bee;
    int total_marks;
};

int main(void)
{
    struct student student[4];

    for (int i = 0; i < 4; i++)
    {
        printf("Please enter the rollNo of %ist student: ", i + 1);
        scanf("%i", &student[i].roll_no);
        printf("\nPlease enter the name of %ist student: ", i + 1);
        scanf("%s", student[i].name);
        printf("\nPlease enter the marks of Math, Physics and BEE respectively: ");
        scanf("%i %i %i", &student[i].marks_math, &student[i].marks_physics, &student[i].marks_bee);
        student[i].total_marks = student[i].marks_bee + student[i].marks_math + student[i].marks_physics;
    }

    // perform bubble sort on total_marks
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3 - i; j++)
        {
            if (student[j].total_marks > student[j + 1].total_marks)
            {
                struct student temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        printf("\n %ist - %s\n", (i + 1), student[i].name);
    }
}
