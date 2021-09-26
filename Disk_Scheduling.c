#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int q[30], n, he, qs[30], l, r, visited[30];
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void fcfs()
{
    int sum = abs(he - q[0]);
    printf("%i -> %i -> ", he, q[0]);
    for (int i = 1; i < n; i++)
    {
        sum += abs(q[i] - q[i - 1]);
        printf("%i -> ", q[i]);
    }
    printf("\n\n%i  ", sum);
}
int findminimum(int val)
{
    int index;
    int sum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (sum > (abs(q[i] - val)) && visited[i] == 0)
        {
            index = i;
            sum = abs(q[i] - val);
        }
    }
    visited[index] = 1;
    return index;
}
void sstf()
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    int e = findminimum(he);
    int sum = abs(he - q[e]);
    printf("%i -> %i -> ", he, q[e]);

    for (int i = 1; i < n; i++)
    {
        int ee = findminimum(q[e]);
        sum += abs(q[e] - q[ee]);
        printf("%i -> ", q[ee]);
        e = ee;
    }
    printf("\n\n%i  ", sum);
}
void cscan()
{
    int e;
    for (int i = 0; i < n; i++)
    {
        if (qs[i] > he)
        {
            e = i;
            break;
        }
    }
    printf("1=left || 2=right");
    int dir;
    scanf("%i", &dir);
    if (dir == 2)
    {
        printf("%i -> ", he);
        for (int i = e; i < n; i++)
            printf("%i -> ", qs[i]);
        printf("%i -> %i -> ", r, l);
        for (int i = 0; i < e; i++)
            printf("%i -> ", qs[i]);
    }
    else
    {
        printf("%i -> ", he);
        for (int i = e - 1; i >= 0; i--)
            printf("%i -> ", qs[i]);
        printf("%i -> %i -> ", l, r);
        for (int i = n - 1; i >= e; i--)
            printf("%i -> ", qs[i]);
    }
    int sum = r - he + qs[e - 1] - l + r - l;
    printf("\n\n%i  ", sum);
}
void look()
{
    int e;
    for (int i = 0; i < n; i++)
    {
        if (qs[i] > he)
        {
            e = i;
            break;
        }
    }
    printf("1=left || 2=right");
    int dir;
    scanf("%i", &dir);
    if (dir == 2)
    {
        printf("%i -> ", he);
        for (int i = e; i < n; i++)
            printf("%i -> ", qs[i]);
        // printf("%i -> ", r);
        for (int i = e - 1; i <= 0; i--)
            printf("%i -> ", qs[i]);
        int sum = qs[n - 1] - he + qs[n - 1] - qs[0];
        printf("\n\n%i  ", sum);
    }
    else
    {
        printf("%i -> ", he);
        for (int i = e - 1; i >= 0; i--)
            printf("%i -> ", qs[i]);
        // printf("%i -> ", l);
        for (int i = e; i < n; i++)
            printf("%i -> ", qs[i]);
        int sum = he - qs[0] + qs[n - 1] - qs[0];
        printf("\n\n%i  ", sum);
    }
}
void scan()
{
    int e;
    for (int i = 0; i < n; i++)
    {
        if (qs[i] > he)
        {
            e = i;
            break;
        }
    }
    printf("1=left || 2=right");
    int dir;
    scanf("%i", &dir);
    if (dir == 2)
    {
        printf("%i -> ", he);
        for (int i = e; i < n; i++)
            printf("%i -> ", qs[i]);
        printf("%i -> ", r);
        for (int i = e - 1; i <= 0; i--)
            printf("%i -> ", qs[i]);
        int sum = r - he + r - qs[0];
        printf("\n\n%i  ", sum);
    }
    else
    {
        printf("%i -> ", he);
        for (int i = e - 1; i >= 0; i--)
            printf("%i -> ", qs[i]);
        printf("%i -> ", l);
        for (int i = e; i < n; i++)
            printf("%i -> ", qs[i]);
        int sum = he - l + qs[n - 1] - l;
        printf("\n\n%i  ", sum);
    }
}
void clook()
{
    int e;
    for (int i = 0; i < n; i++)
    {
        if (qs[i] > he)
        {
            e = i;
            break;
        }
    }
    printf("1=left || 2=right");
    int dir;
    scanf("%i", &dir);
    if (dir == 2)
    {
        printf("%i -> ", he);
        for (int i = e; i < n; i++)
            printf("%i -> ", qs[i]);
        // printf("%i -> %i -> ", r, l);
        for (int i = 0; i < e; i++)
            printf("%i -> ", qs[i]);
    }
    else
    {
        printf("%i -> ", he);
        for (int i = e - 1; i >= 0; i--)
            printf("%i -> ", qs[i]);
        // printf("%i -> %i -> ", l, r);
        for (int i = n - 1; i >= e; i--)
            printf("%i -> ", qs[i]);
    }
    int sum = qs[n - 1] - he + qs[e - 1] - qs[0] + qs[n - 1] - qs[0];
    printf("\n\n%i  ", sum);
}
int main(int argc, char const *argv[])
{
    printf("Enter l & r :\t");
    scanf("%i %i", &l, &r);
    printf("Enter the length of queue :\t");
    scanf("%i", &n);
    printf("Enter the queue :\n");
    for (int i = 0; i < n; i++)
        scanf("%i", &q[i]);
    printf("Enter the Current head :\t");
    scanf("%i", &he);
    for (int loop = 0; loop < n; loop++)
    {
        qs[loop] = q[loop];
    }
    qsort(qs, n, sizeof(int), cmpfunc);
    // cscan();
    // clook();
    // scan();
    // fcfs();
    // sstf();
    // look();
    while (1)
    {
        printf("\n1.FCFS\n");
        printf("2.SCAN\n");
        printf("3.C-SCAN\n");
        printf("4.LOOK\n");
        printf("5.C-LOOK\n");
        printf("6.SSTF\n");
        printf("7.Exit\n");
        printf("Enter your choice\n");
        int c;
        scanf("%i", &c);
        switch (c)
        {
        case 1:
            fcfs();
            break;
        case 2:
            scan();
            break;
        case 3:
            cscan();
            break;
        case 4:
            look();
            break;
        case 5:
            clook();
            break;
        case 6:
            sstf();
            break;
        case 7:
            exit(0);
        default:
            printf("Enter a correct option\n");
            break;
        }
        printf("\n");
    }
    return 0;
}
