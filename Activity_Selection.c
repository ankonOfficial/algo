#include <stdio.h>

void activitySelection(int start[], int finish[], int n)
{
    int i, j;

    printf("Selected activities:\n");

    i = 0;
    printf("Activity %d\n", i + 1);

    for (j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            printf("Activity %d\n", j + 1);
            i = j;
        }
    }
}

int main()
{
    int n, i;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter start times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &start[i]);

    printf("Enter finish times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &finish[i]);

    activitySelection(start, finish, n);

    return 0;
}
