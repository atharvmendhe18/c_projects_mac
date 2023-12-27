// WAP to store the radius and center of a circle using a nested structure. Display the information of radius and center.

#include <stdio.h>

struct circle
{
    int radius;
    struct center
    {
        int x_coordinate;
        int y_coordinate;
    } center;
};

int main(void)
{
    struct circle circle1;
    struct center center1;
    circle1.radius = 10;
    circle1.center.x_coordinate = 2;
    circle1.center.y_coordinate = 7;

    printf("Radius = %i, X = %i, Y = %i ", circle1.radius, circle1.center.x_coordinate, circle1.center.y_coordinate);
}