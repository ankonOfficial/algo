#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int node)
{
    int i;

    visited[node] = 1;
    printf("%d ", node);

    for (i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}
