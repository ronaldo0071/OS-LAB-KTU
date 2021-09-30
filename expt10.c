#include <stdio.h>
#include <stdlib.h>
int n, a[40], f, c;
void fifo()
{
    int aa[f];
    int i, j, co = 0;
    for (i = 0; i < f; i++)
    {
        aa[i] = -1;
    }
    co = 0;
    for (i = 0, j = 0; i < n; i++)
    {
        int fo = 0;
        for (int ii = 0; ii < f; ii++)
        {
            if (aa[ii] == a[i])
            {
                fo = 1;
            }
        }
        if (fo == 1)
        {
            continue;
        }
        else
        {
            aa[j] = a[i];
            j = (j + 1) % f;
            co++;
            
        }
    }
    printf("Number of Page faults : %i\n\n", co);
}
void opt()
{
    int aa[f];
    int i, j, co = 0, e = 0;
    for (i = 0; i < f; i++)
    {
        aa[i] = -1;
    }
    for (i = 0; i < n; i++) //for filling frame initially
    {
        int fo = 0;
        for (int ii = 0; ii < f; ii++)
        {
            if (aa[ii] == a[i])
            {
                fo = 1;
            }
        }
        if (fo == 1)
        {
            continue;
        }
        else
        {
            aa[co] = a[i];
            co++;
            if (co == f)
            {
                e = i;
                break;
            }
        }
    }
   
    for (i = e + 1; i < n; i++)
    {
        int fo = 0;
        for (int ii = 0; ii < f; ii++)
        {
            if (aa[ii] == a[i])
            {
                fo = 1;
            }
        }
        if (fo == 1)
        {
            continue;
        }
        else
        {
            int s = 0, si = 0, t, ti, r;
            if (i == n - 1)
            {
                co++;
            }
            else
            {
                for (int kk = 0; kk < f; kk++)
                {
                    t = 0;
                    for (r = i + 1; r < n; r++)
                    {
                        t++;
                        if (aa[kk] == a[r])
                        {
                            break;
                        }
                    }
                    if (r == n && aa[kk] != a[r])
                    {
                        t++;
                    }
                    
                    if (s < t)
                    {
                        si = kk;
                        s = t;
                    }
                }
                aa[si] = a[i];
                co++;
                printf("\n");
                printf("\n");
            }
        }
    }
    printf("Number of Page faults : %i\n\n", co);
}
void lru()
{
    int aa[f];
    int i, j, co = 0, e = 0;
    for (i = 0; i < f; i++)
    {
        aa[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        int fo = 0;
        for (int ii = 0; ii < f; ii++)
        {
            if (aa[ii] == a[i])
            {
                fo = 1;
            }
        }
        if (fo == 1)
        {
            continue;
        }
        else
        {
            co++;
            aa[co - 1] = a[i];
            if (co == f)
            {
                e = i;
                break;
            }
        }
    }
    
    for (i = e + 1; i < n; i++)
    {
        int fo = 0;
        for (int ii = 0; ii < f; ii++)
        {
            if (aa[ii] == a[i])
            {
                fo = 1;
            }
        }
        if (fo == 1)
        {
            continue;
        }
        else
        {
            int s = 0, si = 0, t, ti;

            for (int kk = 0; kk < f; kk++)
            {
                t = 0;
                ti = kk;
                int r;
                for (r = i - 1; r >= 0; r--)
                {
                    t++;
                    if (aa[ti] == a[r])
                    {
                        break;
                    }
                }
                if (r == 0 && aa[kk] != a[r])
                {
                    t++;
                }
                if (s < t)
                {
                    si = ti;
                    s = t;
                }
            }
            aa[si] = a[i];
            co++;
                 }
    }
    printf("Number of Page faults : %i\n\n", co);
}
main()
{

    printf("Enter the length of reference string\n");
    scanf("%i", &n);
    printf("Enter the Reference string\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &a[i]);
    }
    printf("Enter the number of frames\n");
    scanf("%i", &f);
    while (1)
    {
        printf("\n1.FIFO\n");
        printf("2.Optimal\n");
        printf("3.LRU\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%i", &c);
        switch (c)
        {
        case 1:
            fifo();
            break;
        case 2:
            opt();
            break;
        case 3:
            lru();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter correct option\n");
        }
    }
    printf("\n");
    printf("\n");
}
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
/*
7
0
1
2
0
3
0
4
2
3
0
3
2
*/