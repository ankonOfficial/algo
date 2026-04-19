#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, W, i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;

            else if (weight[i - 1] <= w)
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]],
                              K[i - 1][w]);

            else
                K[i][w] = K[i - 1][w];
        }
    }

    printf("Maximum value in knapsack = %d\n", K[n][W]);

    return 0;
}
