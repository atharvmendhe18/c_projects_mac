#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int input_to_sort[10];

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
        if (input_to_sort[i] > max_no)
        {
            max_no = input_to_sort[i];
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
    int lenght = 0;
    while (no / 10 != 0)
    {
        lenght++;
        no = no / 10;
    }
    return lenght;
}
void radix_sort()
{
    int updated[10] = input_to_sort;
    struct bucket my_buckets[10];
    int no_of_iterations = lenght_max_no();
    int iterations = 1;
    while (iterations <= no_of_iterations) // go through all the passes for radix sort
    {
        struct bucket my_buckets[10];
        int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0;
        // now start to place numbers in buckets
        for (int i = 0; i < 10; i++)
        {
            if (num_length(updated[i]) < iterations)
            {
                my_buckets[0].inside_bucket[i0++] = updated[i];
            }
            else
            {
                int num = updated[i];

                for (int i = 1; i < iterations; i++)
                {
                    num = num / 10;
                }
                int iteration_digit = num % 10;

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
        for (int k = 0; k < 10; k++)
        {
            int l = 0;
            while (my_buckets[k].inside_bucket[0] != NULL)
            {
                updated[p++] = my_buckets[k].inside_bucket[l++];
            }
        }
    }
    int o = 0;
    while (updated[o] != NULL)
    {
        printf("%i", updated[o++]);
    }
}
int main()
{
    printf("Enter the numbers in array:");
    for (int i = 0; i < 3; i++)
    {
        scanf("%i", &input_to_sort[i]);
    }
    printf("%i", lenght_max_no());

    return 0;
}