#include <stdio.h>
struct pro
{
    int name;
    int ari;
    int bur;
    int prio;
    int comp;
    int turn;
    int wait;
    int vis;
    int rem;
} p[10];
//scanf("%i",&); printf("\n");
int a[2][100], hh;
int n;
void sca()
{
    printf("Enter no. of processes\n");
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        //printf("Enter arr,bur,prio of p%i\n",i+1);
        scanf("%i %i", &p[i].ari, &p[i].bur);
        p[i].name = i + 1;
    }
}
void clr()
{
    for (int i = 0; i < n; i++)
    {
        p[i].comp = 0;
        p[i].vis = 0;
        p[i].rem = p[i].bur;
    }
    for (int i = 0; i <= hh; i++)
    {
        a[0][i] = 0;
        a[1][i] = 0;
    }
}
void dis()
{
    for (int i = 0; i < n; i++)
    {
        printf("P%i %i\n", p[i].name, p[i].comp);
    }
    printf("\n");
    printf("Gan\n");
    printf("p%i ", a[0][0]);
    printf("%i %i\n", a[1][0], a[1][1]);
    for (int i = 2; i <= hh; i++)
    {
        printf("p%i ", a[0][i]);
        printf("%i %i\n", a[1][i - 1], a[1][i]);
    }
    printf("\n");
}
void sort()
{
    int i, j, mi;
    for (i = 0; i < n; i++)
    {
        mi = i;
        for (j = i + 1; j < n; j++)
        {
            if (p[j].ari < p[mi].ari)
            {
                mi = j;
            }
        }
        struct pro te = p[mi];
        p[mi] = p[i];
        p[i] = te;
    }
}
void cal()
{
    for (int i = 0; i < n; i++)
    {
        p[i].turn = p[i].comp - p[i].ari;
        p[i].wait = p[i].turn - p[i].bur;
    }
}
void fcfs()
{
    sort();
    clr();
    for (int i = 0; i < n; i++)
    {
        printf("p%i %i\n", p[i].ari, p[i].name);
    }
    int co = 0, i;
    co = p[0].ari;
    co += p[0].bur;
    p[0].comp = co;
    printf("comp %i\n", p[0].comp);
    for (i = 1; i < n; i++)
    {
        if (p[i].ari > co)
        {
            co = p[i].ari;
        }
        co += p[i].bur;
        p[i].comp = co;
    }
    cal();
    dis();
}
void sjf()
{
    sort();
    clr();
    int i, co, g;
    int mi = 0;
    for (i = 1; i < n; i++)
    {
        if (p[i].ari == p[0].ari && p[mi].bur > p[i].bur)
        {
            mi = i;
        }
    }

    co = p[mi].ari;
    co += p[mi].bur;
    p[mi].comp = co;
    p[mi].vis = 1;
    //int cou=1;
    g = 2;
    for (i = 0; i < n;)
    {
        if (p[i].vis == 0)
        {
            if (p[i].ari <= co)
            {
                int j;
                mi = i;
                for (j = i + 1; j < n; j++)
                {
                    if (p[j].ari <= co && p[j].bur < p[mi].bur && p[j].vis != 1)
                    {
                        mi = j;
                    }
                }
                co += p[mi].bur;
                p[mi].comp = co;
                p[mi].vis = 1;
            }
            else
            {
                co++;
            }
        }
        else
        {
            i++;
        }
    }
    cal();
    dis();
}
void srtf()
{
    sort();
    clr();
    int i, co, g, j, k;
    int mi = 0;
    co = p[0].ari;
    int cou = 0;
    for (i = 0; i < n;)
    {
        printf("\n%i\n", i);
        if (p[i].rem != 0)
        {
            if (co >= p[i].ari)
            {
                for (j = 0; j < n; j++)
                {
                    printf("\nmi:%i\n", mi);
                    if (p[j].rem > 0 && p[j].ari <= co && p[j].rem < p[mi].rem)
                    {
                        mi = j;
                    }
                }
                int why = 0;
                for (k = 1; k <= p[mi].rem; k++)
                {
                    int jk = 0;
                    for (j = 0; j < n; j++)
                    {
                        if (p[j].rem > 0 && p[j].ari <= co + k && p[j].rem < (p[mi].rem - k))
                        {
                            printf("\nfgfgfg\n");

                            p[mi].rem -= k;
                            if (p[mi].rem == 0)
                            {
                                p[mi].comp = co;
                            }
                            co += k;
                            mi = j;
                            jk = 1;
                            break;
                        }
                    }
                    if (jk == 1)
                    {
                        why = 1;
                        break;
                    }
                }
                if (why != 1)
                {
                    //printf("\nfd\n");
                    co = co + p[mi].rem;
                    p[mi].comp = co;
                    p[mi].rem = 0;
                    //printf("\nremain:%i, mi:%i\n",p[mi].rem,mi);
                    for (int y = 0; y < n; y++)
                    {
                        if (p[y].rem != 0)
                        {
                            mi = y;
                            //printf("\nChanges %i\n",mi);
                            break;
                        }
                    }
                }
            }
            else
            {
                co++;
            }
        }
        else
        {
            i++;
        }
    }
    dis();
}
void priop() {}
void prion() {}
void rb()
{
    int requ[100], tq;
    printf("enter tq\n");
    scanf("%i", &tq);
    clr();
    int i, ptr = 0, co, ind, ptr2 = 1;
    for (i = 0; i < 100; i++)
    {
        requ[i] = -1;
    }
    int minu = 0;
    for (i = 0; i < n; i++)
    {
        if (p[minu].ari > p[i].ari)
        {
            minu = i;
        }
    }
    requ[ptr] = minu;
    co = p[minu].ari;
    while (requ[ptr] != -1)
    {
        int k, m;
        ind = requ[ptr];
        p[ind].vis = 1;
        //printf("\nptr:%i\n",ptr);
        if (p[ind].rem >= tq)
        {
            k = tq;
        }
        else
        {
            k = p[ind].rem;
        }
        
        //printf("\np%i :%i\n",ind+1,p[ind].rem);
        for (m = co; m <= co + k; m++)
        {
            for (int gg = 0; gg < n; gg++)
            {
                if (p[gg].vis != 1 && m >= p[gg].ari)
                {
                    p[gg].vis = 1;
                    requ[ptr2] = p[gg].name - 1;
                    ptr2++;
                }
            }
        }
        co += k;
        p[ind].rem -= k;
        if (p[ind].rem == 0)
        {
            p[ind].comp = co;
        }
        else
        {
            requ[ptr2] = p[ind].name - 1;
            ptr2++;
        }
        ptr++;
    }
    dis();
}
int main()
{
    sca();
    int ii;
    while (1)
    {
        printf("1.FCFS\n");
        printf("2.SJF\n");
        printf("3.SRTF\n");
        printf("4.PRIO_PRE\n");
        printf("5.PRIO_NONPRE\n");
        printf("6.RB\n");
        printf("7.Exit\n");
        printf("Enter your choice\n");
        scanf("%i", &ii);
        switch (ii)
        {
        case 1:
            fcfs();
            break;
        case 2:
            sjf();
            break;
        case 3:
            srtf();
            break;
        case 4:
            priop();
            break;
        case 5:
            prion();
            break;
        case 6:
            rb();
            break;
        case 7:
            exit(0);
        default:
            printf("Enter correct\n");
        }
    }
}
/*
2 2 1
0 1 1
2 3 1
3 5 1
4 4 1

0 3 3
1 6 4
2 1 9
3 2 7
4 4 8

0 8 1
5 2 1
1 7 1
6 3 1
8 5 1
*/