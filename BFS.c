#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

int dequeue()
{
    int value;
    if (front == -1 || front > rear)
        return -1;
    else
    {
        value = queue[front];
        front++;
        return value;
    }
}

int isEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int main()
{
    int graph[MAX][MAX];
    int visited[MAX];
    int n, i, j, start, node;

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

    printf("Enter starting node: ");
    scanf("%d", &start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty())
    {
        node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
