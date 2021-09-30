#include <stdio.h>
#include <stdlib.h>
int n, a[100][100], m, max[100][100], ava[100], ned[100][100];
int bankers()
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     printf("%i ",ned[i][j]);
    //     printf("\n");
    // }
    {
        int alble[100];
        for (int j = 0; j < m; j++)
        {
            alble[j] = ava[j];
        }
        int visited[n];
        for (int j = 0; j < n; j++)
        {
            visited[j] = 0;
        }
        int proc[n], x = 0, c = 0, d = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (visited[j] == 0)
                {
                    int check = 0;
                    for (int k = 0; k < m; k++)
                    {
                        if (alble[k] < ned[j][k])
                            check = 1;
                    }
                    if (check == 0 && visited[j] == 0)
                    {
                        // printf("p%i ",j);
                        for (int k = 0; k < m; k++)
                        {
                            alble[k] += a[j][k];
                        }
                        visited[j] = 1;
                        proc[x++] = j;
                        // printf("p%i", proc[x - 1]);
                        c++;
                        break;
                    }
                }
            }
            if (c == n)
                d = 1;
        }
        if (c == n)
            for (int i = 0; i < n; i++)
                printf("p%i ", proc[i]);
        else
            printf("sorry");
    }
    printf("\n");
    {
        int alble[100];
        for (int j = 0; j < m; j++)
        {
            alble[j] = ava[j];
        }
        int visited[n];
        for (int j = 0; j < n; j++)
        {
            visited[j] = 0;
        }
        int proc[n], x = 0, c = 0, d = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (visited[j] == 0)
                {
                    int check = 0;
                    for (int k = 0; k < m; k++)
                    {
                        if (alble[k] < ned[j][k])
                            check = 1;
                    }
                    if (check == 0 && visited[j] == 0)
                    {
                        // printf("p%i ",j);
                        for (int k = 0; k < m; k++)
                        {
                            alble[k] += a[j][k];
                        }
                        visited[j] = 1;
                        proc[x++] = j;
                        // printf("p%i", proc[x - 1]);
                        c++;
                    }
                }
            }
            if (c == n)
                d = 1;
        }
        if (c == n)
            for (int i = 0; i < n; i++)
                printf("p%i ", proc[i]);
        else
            printf("sorry");
    }
    printf("\n");
    {
        int alble[100];
        for (int j = 0; j < m; j++)
        {
            alble[j] = ava[j];
        }
        int visited[n];
        for (int j = 0; j < n; j++)
        {
            visited[j] = 0;
        }
        int proc[n], x = 0, c = 0, d = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[j] == 0)
                {
                    int check = 0;
                    for (int k = 0; k < m; k++)
                    {
                        if (alble[k] < ned[j][k])
                            check = 1;
                    }
                    if (check == 0 && visited[j] == 0)
                    {
                        // printf("p%i ",j);
                        for (int k = 0; k < m; k++)
                        {
                            alble[k] += a[j][k];
                        }
                        visited[j] = 1;
                        proc[x++] = j;
                        // printf("p%i", proc[x - 1]);
                        c++;
                    }
                }
            }
            if (c == n)
                d = 1;
        }
        if (c == n)
            for (int i = 0; i < n; i++)
                printf("p%i ", proc[i]);
        else
            printf("sorry");
    }
}
int main(int argc, char const *argv[])
{
    scanf("%i %i", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%i", &a[i][j]);
        }
        for (int j = 0; j < m; j++)
        {
            scanf("%i", &max[i][j]);
        }
        for (int j = 0; j < m; j++)
        {
            ned[i][j] = max[i][j] - a[i][j];
        }
    }
    for (int j = 0; j < m; j++)
        scanf("%i", &ava[j]);
    bankers();
    return 0;
}
/*
5 4
0 0 1 2
0 0 1 2
1 0 0 0
1 7 5 0
1 3 5 4
2 3 5 6
0 6 3 2
0 6 5 2
0 0 1 4
0 6 5 6
1 5 2 0
*/