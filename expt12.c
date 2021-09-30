#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int q[30], h, n, he, qs[30], l, r;
struct qq
{
    int da;
    int vis;
} qu[30];
int minind(int s)
{
    int sm = INT_MAX, si;
    for (int i = 0; i < n; i++)
    {
        if ((sm > abs(s - qs[i])) && qu[i].vis == 0)
        {
            sm = abs(s - qs[i]);
            si = i;
        }
    }
    qu[si].vis = 1;
    return si;
}
void sstf()
{
    int i;
    for (i = 0; i < n; i++)
    {
        qu[i].da = qs[i];
        qu[i].vis = 0;
    }
    int cou = 0, e, ee = he, s = 0;
    printf("The Seek Sequence :\t ");
    printf("%i", he);
    while (cou != n)
    {
        e = minind(ee);
        printf("->%i", qs[e]);
        s = s + abs(qs[e] - ee);
        cou++;
        ee = qs[e];
    }
    printf("\n");
    printf("Total head movement :\t%d\n", s);
}
void fcfs()
{
    int s = 0;
    int j;
    for (j = 1; j < n + 1; j = j + 1)
    {
        s = s + abs(q[j] - q[j - 1]);
    }
    printf("The Seek Sequence :\t ");
    printf("%i", q[0]);
    for (j = 1; j < n + 1; j++)
    {
        printf("->%i", q[j]);
    }
    printf("\n");
    printf("Total head movement :\t%d\n", s);
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sorti(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
void scan()
{
    int yy, k, i, j;
    int min;
    int s = 0;
    printf("Enter the direction right=1 | left =0\n");
    scanf("%i", &yy);
    if (yy == 1)
    {
        for (j = 0; j < n; j++)
        {
            if (he < qs[j])
            {
                k = j;
                break;
            }
        }
        s = s + abs(qs[k] - he);
        printf("The Seek Sequence :\t ");
        printf("%i->%i", he, qs[k]);
        for (j = k + 1; j < n; j++)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        s = s + abs(r - qs[n - 1]) + abs(r - qs[k - 1]);
        printf("->%i", r);
        for (j = k - 1; j > 0; j--)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        printf("->%i", qs[0]);
        printf("\n");
        printf("Total head movement :\t%d\n", s);
    }
    else
    {
        for (j = 0; j < n; j++)
        {
            if (he < qs[j])
            {
                k = j - 1;
                break;
            }
        }
        s = s + abs(qs[k] - he);
        printf("The Seek Sequence :\t ");
        printf("%i", he);
        for (j = k; j > 0; j--)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        printf("->%i->%i->%i", qs[0], l, qs[k + 1]);
        s = s + abs(l - qs[0]) + abs(qs[k + 1] - l);
        for (j = k + 2; j < n; j++)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }

        printf("\n");
        printf("Total head movement :\t%d\n", s);
    }
    printf("\n");
}
void cscan()
{
    int yy, i, j, k, s = 0;
    printf("Enter the direction right=1 | left =0\n");
    scanf("%i", &yy);
    if (yy == 1)
    {
        for (j = 0; j < n; j++)
        {
            if (he < qs[j])
            {
                k = j;
                break;
            }
        }
        s = s + abs(qs[k] - he);
        printf("The Seek Sequence :\t ");
        printf("%i->%i", he, qs[k]);
        for (j = k + 1; j < n; j++)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        s = s + abs(r - qs[n - 1]) + abs(r - l) + abs(l - qs[0]);
        printf("->%i->%i", r, l);
        for (j = 0; j < k - 1; j++)
        {
            s = s + abs(qs[j] - qs[j + 1]);
            printf("->%i", qs[j]);
        }
        printf("->%i", qs[k - 1]);
        printf("\n");
        printf("Total head movement :\t%d\n", s);
    }
    else
    {
        for (j = 0; j < n; j++)
        {
            if (he < qs[j])
            {
                k = j - 1;
                break;
            }
        }
        s = s + abs(qs[k] - he);
        printf("The Seek Sequence :\t ");
        printf("%i", he);
        for (j = k; j > 0; j--)
        {
            s = s + abs(qs[j] - qs[j - 1]);

            printf("->%i", qs[j]);
        }
        printf("->%i->%i->%i", qs[0], l, r);
        s = s + abs(l - qs[0]) + abs(r - l) + abs(r - qs[n - 1]);

        for (j = n - 1; j > k + 1; j--)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        printf("->%i", qs[k + 1]);
        printf("\n");
        printf("Total head movement :\t%d\n", s);
    }
    printf("\n");
}
void look()
{
    int yy, k, i, j;
    int min;
    int s = 0;
    printf("Enter the direction right=1 | left =0\n");
    scanf("%i", &yy);
    if (yy == 1)
    {
        for (j = 0; j < n; j++)
        {
            if (he < qs[j])
            {
                k = j;
                break;
            }
        }
        s = s + abs(qs[k] - he);
        printf("The Seek Sequence :\t ");
        printf("%i->%i", he, qs[k]);
        for (j = k + 1; j < n; j++)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        s = s + abs(qs[n - 1] - qs[k - 1]);
        for (j = k - 1; j > 0; j--)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        printf("->%i", qs[0]);
        printf("\n");
        printf("Total head movement :\t%d\n", s);
    }
    else
    {
        for (j = 0; j < n; j++)
        {
            if (he < qs[j])
            {
                k = j - 1;
                break;
            }
        }
        s = s + abs(qs[k] - he);
        printf("The Seek Sequence :\t ");
        printf("%i", he);
        for (j = k; j > 0; j--)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        printf("->%i", qs[0]);
        s = s + abs(qs[k + 1] - qs[0]);
        for (j = k + 2; j < n; j++)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }

        printf("\n");
        printf("Total head movement :\t%d\n", s);
    }
    printf("\n");
}
void clook()
{
    int yy, i, j, k, s = 0;
    printf("Enter the direction right=1 | left =0\n");
    scanf("%i", &yy);
    if (yy == 1)
    {
        for (j = 0; j < n; j++)
        {
            if (he < qs[j])
            {
                k = j;
                break;
            }
        }
        s = s + abs(qs[k] - he);
        printf("The Seek Sequence :\t ");
        printf("%i->%i", he, qs[k]);
        for (j = k + 1; j < n; j++)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        s = s + abs(qs[n - 1] - qs[0]);
        for (j = 0; j < k - 1; j++)
        {
            s = s + abs(qs[j] - qs[j + 1]);
            printf("->%i", qs[j]);
        }
        printf("->%i", qs[k - 1]);
        printf("\n");
        printf("Total head movement :\t%d\n", s);
    }
    else
    {
        for (j = 0; j < n; j++)
        {
            if (he < qs[j])
            {
                k = j - 1;
                break;
            }
        }
        s = s + abs(qs[k] - he);
        printf("The Seek Sequence :\t ");
        printf("%i", he);
        for (j = k; j > 0; j--)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        printf("->%i", qs[0]);
        s = s + abs(qs[0] - qs[n - 1]);
        for (j = n - 1; j > k + 1; j--)
        {
            s = s + abs(qs[j] - qs[j - 1]);
            printf("->%i", qs[j]);
        }
        printf("->%i", qs[k + 1]);
        printf("\n");
        printf("Total head movement :\t%d\n", s);
    }
    printf("\n");
}
main()
{
    int c;
    printf("Enter the range l and r\n");
    scanf("%i %i", &l, &r);
    printf("Enter the head pointer\n");
    scanf("%i", &he);
    printf("Enter the length of queue\n");
    scanf("%i", &n);
    printf("Enter the elements\n");
    q[0] = he;
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%i", &q[i]);
    }
    for (int i = 1; i < n + 1; i++)
    {
        qs[i - 1] = q[i];
    }
    sorti(qs, n);
    printf("\n");
    while (1)
    {
        printf("1.FCFS\n");
        printf("2.SCAN\n");
        printf("3.C-SCAN\n");
        printf("4.LOOK\n");
        printf("5.C-LOOK\n");
        printf("6.SSTF\n");
        printf("7.Exit\n");
        printf("Enter your choice\n");
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
}
//82 170 43 140 24 16 190