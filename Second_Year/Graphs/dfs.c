#include <stdio.h>
#include <stdlib.h>

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

void dfs(int i)
{
    printf("%i ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (graph[i][j] == 1 && visited[j] == 0)
        {
            dfs(j);
        }
    }
}

void main()
{
    dfs(1);
}