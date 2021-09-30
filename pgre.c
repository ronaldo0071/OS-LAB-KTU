#include <stdio.h>
#include <stdlib.h>
int pg[100], n, f;
void fifo()
{
    int frame[f];
    for (int i = 0; i < f; i++)
        frame[i] = -1;
    int c = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        int fch = 0;
        for (int j = 0; j < f; j++)
        {
            if (pg[i] == frame[j])
                fch = 1;
        }
        if (fch == 0)
        {
            frame[k] = pg[i];
            k = (k + 1) % f;
            c++;
        }
    }
    printf("\npf :%i", c);
}
void opt()
{
    int frame[f];
    for (int i = 0; i < f; i++)
        frame[i] = -1;
    int c = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        int fch = 0;
        for (int j = 0; j < f; j++)
        {
            if (pg[i] == frame[j])
                fch = 1;
        }
        if (fch == 0)
        {
            frame[c++] = pg[i];
            if (f == c)
            {
                e = i;
                break;
            }
        }
    }
    printf("\npf :%i", c);
    for (int i = e + 1; i < n; i++)
    {
        int fch = 0;
        for (int j = 0; j < f; j++)
        {
            if (pg[i] == frame[j])
            {
                fch = 1;
            }
        }
        if (fch == 1)
            continue;
        else
        {
            printf("%i ", pg[i]);
            if (i == n - 1)
                c++;
            else
            {

                int s = 0, si = 0, t = 0;
                for (int k = 0; k < f; k++)
                {
                    int j;
                    t = 0;
                    for (j = i + 1; j < n; j++)
                    {
                        t++;
                        if (frame[k] == pg[j])
                            break;
                    }
                    if (j == n && pg[n - 1] != frame[k])
                        t++;
                    if (s < t)
                    {
                        s = t;
                        si = k;
                    }
                }
                c++;
                frame[si] = pg[i];
            }
        }
    }
    printf("\npf :%i", c);
}
void lru()
{
    int frame[f];
    for (int i = 0; i < f; i++)
        frame[i] = -1;
    int c = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        int fch = 0;
        for (int j = 0; j < f; j++)
        {
            if (pg[i] == frame[j])
                fch = 1;
        }
        if (fch == 0)
        {
            frame[c++] = pg[i];
            if (f == c)
            {
                e = i;
                break;
            }
        }
    }
    printf("\npf :%i", c);
    for (int i = e + 1; i <n; i++)
    {
        int fch = 0;
        for (int j = 0; j < f; j++)
        {
            if (pg[i] == frame[j])
            {
                fch = 1;
            }
        }
        if (fch == 1)
            continue;
        else
        {
            // printf("%i ", pg[i]);
            

                int s = 0, si = 0, t = 0;
                for (int k = 0; k < f; k++)
                {
                    int j;
                    t = 0;
                    for (j = i - 1; j >=0; j--)
                    {
                        t++;
                        if (frame[k] == pg[j])
                            break;
                    }
                    if (j == -1)
                        t++;
                    if (s < t)
                    {
                        s = t;
                        si = k;
                    }
                }
                c++;
                frame[si] = pg[i];
            
        }
    }
    printf("\npf :%i", c);
}
int main(int argc, char const *argv[])
{
    /* code */
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
        scanf("%i", &pg[i]);
    scanf("%i", &f);
    // fifo();
    // opt();
    lru();
    return 0;
}
/*
13
7 0 1 2 0 3 0 4 2 3 0 3 2
3
*/