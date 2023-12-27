#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int updated[10];

typedef struct bucket
{
    int inside_bucket[10];
} bucket;

int lenght_max_no()
{
    printf("Using the lenght_max_no fucntion\n");
    int lenght_of_max_no;
    int max_no = 0;
    for (int i = 0; i < 10; i++)
    {
        if (updated[i] > max_no)
        {
            max_no = updated[i];
        }
    }
    while (max_no / 10 != 0)
    {
        lenght_of_max_no++;
        max_no = max_no / 10;
    }
    return lenght_of_max_no;
}

int num_length(int no)
{
    printf("Used num_lenght fucntion\n");
    int lenght = 0;
    while (no / 10 != 0)
    {
        lenght++;
        no = no / 10;
    }
    return lenght + 1;
}
void radix_sort()
{
    struct bucket my_buckets[10];
    int no_of_iterations = lenght_max_no();
    int iterations = 1;
    printf("Before while loop\n");
    while (iterations <= no_of_iterations + 1) // go through all the passes for radix sort
    {
        printf("In the %ith iteration of while loop\n", iterations);
        struct bucket my_buckets[10];
        int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0;
        // now start to place numbers in buckets
        for (int i = 0; i < 3; i++)
        {
            printf("In the for loop doing %ith loop\n", i);
            if (num_length(updated[i]) < iterations)
            {
                printf("Went through the short number condition\n");
                my_buckets[0].inside_bucket[i0++] = updated[i];
            }
            else
            {
                printf("Now in the else condition\n");
                int num = updated[i];

                for (int i = 1; i < iterations; i++)
                {
                    num = num / 10;
                }
                int iteration_digit = num % 10;
                printf("The iteration digit is %i\n", iteration_digit);
                switch (iteration_digit)
                {
                case 0:
                    my_buckets[iteration_digit].inside_bucket[i0++] = updated[i];
                    break;
                case 1:
                    my_buckets[iteration_digit].inside_bucket[i1++] = updated[i];
                    break;
                case 2:
                    my_buckets[iteration_digit].inside_bucket[i2++] = updated[i];
                    break;
                case 3:
                    my_buckets[iteration_digit].inside_bucket[i3++] = updated[i];
                    break;
                case 4:
                    my_buckets[iteration_digit].inside_bucket[i4++] = updated[i];
                    break;
                case 5:
                    my_buckets[iteration_digit].inside_bucket[i5++] = updated[i];
                    break;
                case 6:
                    my_buckets[iteration_digit].inside_bucket[i6++] = updated[i];
                    break;
                case 7:
                    my_buckets[iteration_digit].inside_bucket[i7++] = updated[i];
                    break;
                case 8:
                    my_buckets[iteration_digit].inside_bucket[i8++] = updated[i];
                    break;
                case 9:
                    my_buckets[iteration_digit].inside_bucket[i9++] = updated[i];
                    break;
                }
            }
        }
        printf("Before the all NULL statements\n");
        my_buckets[0].inside_bucket[i0++] = NULL;
        my_buckets[1].inside_bucket[i1++] = NULL;
        my_buckets[2].inside_bucket[i2++] = NULL;
        my_buckets[3].inside_bucket[i3++] = NULL;
        my_buckets[4].inside_bucket[i4++] = NULL;
        my_buckets[5].inside_bucket[i5++] = NULL;
        my_buckets[6].inside_bucket[i6++] = NULL;
        my_buckets[7].inside_bucket[i7++] = NULL;
        my_buckets[8].inside_bucket[i8++] = NULL;
        my_buckets[9].inside_bucket[i9++] = NULL;

        int p = 0;
        printf("After the all NULL statements\n");
        for (int k = 0; k < 10; k++)
        {
            printf("Entering the for loop after the NULL statements\n");
            int l = 0;
            while (my_buckets[k].inside_bucket[l] != NULL)
            {
                updated[p++] = my_buckets[k].inside_bucket[l++];
            }
        }
        printf("Completed the for loop afte the NULL statements\n");
        printf("Printing the array after every loop\n");
        printf("\nSTART\n\n");
        int o = 0;
        while (updated[o] != NULL)
        {
            printf("%i\n", updated[o++]);
        }
        printf("\nEND\n\n");
        iterations++;
    }
    printf("Succesfully exited from the while loop\n");
    int o = 0;
    while (updated[o] != NULL)
    {
        printf("%i\n", updated[o++]);
    }
}
int main()
{
    printf("Enter the numbers in array:");
    for (int i = 0; i < 3; i++)
    {
        scanf("%i", &updated[i]);
    }
    printf("%i\n", lenght_max_no());
    radix_sort();

    return 0;
}