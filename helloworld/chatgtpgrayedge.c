#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char *argv[])
{
    // Open the input image file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Error opening input file\n");
        return 1;
    }

    // Read the input image into a buffer
    unsigned char input_image[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            fscanf(input_file, "%hhu", &input_image[i][j]);
        }
    }
    fclose(input_file);

    // Create a buffer for the output image
    unsigned char output_image[WIDTH][HEIGHT];

    // Perform edge detection using the Sobel operator
    for (int i = 1; i < WIDTH - 1; i++)
    {
        for (int j = 1; j < HEIGHT - 1; j++)
        {
            int gx = -input_image[i - 1][j - 1] - 2 * input_image[i][j - 1] - input_image[i + 1][j - 1] + input_image[i - 1][j + 1] + 2 * input_image[i][j + 1] + input_image[i + 1][j + 1];
            int gy = -input_image[i - 1][j - 1] - 2 * input_image[i - 1][j] - input_image[i - 1][j + 1] + input_image[i + 1][j - 1] + 2 * input_image[i + 1][j] + input_image[i + 1][j + 1];
            output_image[i][j] = abs(gx) + abs(gy);
        }
    }

    // Open the output image file
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL)
    {
        fprintf(stderr, "Error opening output file\n");
        return 1;
    }

    // Write the output image to the file
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            fprintf(output_file, "%hhu ", output_image[i][j]);
        }
        fprintf(output_file, "\n");
    }
    fclose(output_file);

    return 0;
}
