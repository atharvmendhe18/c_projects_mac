#include <stdio.h>
#include <stdlib.h>

int queue[40];
int front = -1;
int rear = -1;

// implement queue fucntions

void enqueue(int to_enqueue)
{
    queue[++rear] = to_enqueue;
}

int dequeue()
{
    return queue[++front];
}

int is_empty()
{
    if (rear - front == 0)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    // make a graph using adjency matrix
    int graph[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
    };

    // make a visited array
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int start = 3;
    printf("%i ", start);
    visited[start] = 1;
    enqueue(start);
    while (is_empty() != 1)
    {
        int j = dequeue();
        for (int k = 0; k < 7; k++)
        {
            if (graph[j][k] == 1 && visited[k] == 0)
            {
                printf("%i ", k);
                visited[k] = 1;
                enqueue(k);
            }
        }
    }
}