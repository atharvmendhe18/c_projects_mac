#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char *argv[])
{
    // Check for the correct number of command line arguments
    if (argc != 3)
    {
        printf("Usage: sobel <input_file> <output_file>\n");
        return 1;
    }

    // Open the input and output files
    FILE *in = fopen(argv[1], "rb");
    if (!in)
    {
        printf("Unable to open input file\n");
        return 1;
    }
    FILE *out = fopen(argv[2], "wb");
    if (!out)
    {
        printf("Unable to open output file\n");
        return 1;
    }

    // Read the header information from the input file
    unsigned char header[54];
    fread(header, 1, 54, in);

    // Write the header information to the output file
    fwrite(header, 1, 54, out);

    // Read the pixel data from the input file
    unsigned char pixels[HEIGHT][WIDTH][3];
    fread(pixels, 1, HEIGHT * WIDTH * 3, in);

    // Create a buffer to hold the output pixel data
    unsigned char out_pixels[HEIGHT][WIDTH][3];

    // Loop over each pixel in the image
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            // Initialize the sum of the gradient values to 0
            int sum = 0;

            // Apply the Sobel operator to the pixel
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    // Check if the pixel is within the bounds of the image
                    if (y + i >= 0 && y + i < HEIGHT && x + j >= 0 && x + j < WIDTH)
                    {
                        // Calculate the gradient value for the pixel
                        sum += pixels[y + i][x + j][0] * (i == 0 ? 0 : (i == 1 ? 1 : -1)) * (j == 0 ? 0 : (j == 1 ? 1 : -1));
                    }
                }
            }

            // Set the pixel value to the absolute value of the sum of the gradient values
            out_pixels[y][x][0] = abs(sum);
            out_pixels[y][x][1] = abs(sum);
            out_pixels[y][x][2] = abs(sum);
        }
    }

    // Write the output pixel data to the output file
    fwrite(out_pixels, 1, HEIGHT * WIDTH * 3, out);

    // Close the input and output files
    fclose(in);
    fclose(out);

    return 0;
}