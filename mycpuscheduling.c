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
/*
5
0 2
1 6
2 4
3 9
6 12
*/
int n;
void cal()
{
    for (int i = 0; i < n; i++)
    {
        p[i].turn = p[i].comp - p[i].ari;
        p[i].wait = p[i].turn - p[i].bur;
    }
}
void clr()
{
    for (int i = 0; i < n; i++)
    {
        p[i].name = i + 1;
        p[i].comp = 0;
        p[i].vis = 0;
        p[i].rem = p[i].bur;
    }
}
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
        printf("%i\tp%i\t%i\n", co, p[ind].name, co + k);
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
    display();
}
void srt()
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].ari < p[min].ari)
                min = j;
        }
        struct pro temp = p[i];
        p[i] = p[min];
        p[min] = temp;
    }
}
void display()
{
    cal();
    FILE *fptr;
    fptr = fopen("program.txt", "w");
    fprintf(fptr, "process\t\tAT\tCT\tTAT\tWT");
    for (int i = 0; i < n; i++)
    {
        printf("\nprocess %i : %i\t%i\t%i\t%i", p[i].name, p[i].ari, p[i].comp, p[i].turn, p[i].wait);
        fprintf(fptr, "\nprocess %i : %i\t%i\t%i\t%i", p[i].name, p[i].ari, p[i].comp, p[i].turn, p[i].wait);
    }
    fclose(fptr);
}

void fcfs()
{
    clr();
    srt();
    int co = 0;
    // display();
    for (int i = 0; i < n; i++)
    {
        if (co < p[i].ari)
        {
            co = p[i].ari;
        }
        co += p[i].bur;
        p[i].comp = co;
    }

    display();
}
void sjf()
{
    clr();
    srt();
    int co = p[0].ari, gannli;
    // display();
    int min = 0;
    for (int i = 0; i < n;)
    {
        if (p[i].vis == 0)
        {
            if (p[i].ari <= co)
            {
                min = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (p[j].ari <= co && p[j].vis == 0 && p[min].bur > p[j].bur)
                    {
                        min = j;
                    }
                }
                printf("%i\tp%i\t%i\n", co, p[min].name, co + p[min].bur);
                co += p[min].bur;
                gannli = co;
                p[min].comp = co;
                p[min].vis = 1;
            }
            else
            {
                co++;
                if (p[i].ari <= co)
                    printf("%i\tp-1\t%i\n", gannli, co);
            }
        }
        else
        {
            i++;
        }
    }

    display();
}
void srtf()
{
    clr();
    srt();
    int mi = 0, gannli = 0;
    int co = p[mi].ari;
    for (int i = 0; i < n;)
    {
        if (p[i].rem != 0)
        {
            if (p[i].ari <= co)
            {
                mi = i;
                for (int j = 0; j < n; j++)
                {
                    if (p[j].rem != 0 && p[j].ari <= co && p[j].rem < p[mi].rem)
                        mi = j;
                }
                int check1 = 0;
                for (int k = 1; k <= p[mi].rem; k++)
                {
                    int check2 = 0;
                    for (int j = 0; j < n; j++)
                    {
                        if (p[j].rem != 0 && p[j].ari <= co + k && p[j].rem < (p[mi].rem - k))
                        {
                            check2 = 1;
                            p[mi].rem -= k;
                            printf("%i\tp%i\t%i\n", co, p[mi].name, co + k);
                            co += k;
                            gannli = co;
                            mi = j;
                            break;
                        }
                    }
                    if (check2 == 1)
                    {
                        check1 = 1;
                        break;
                    }
                }
                if (check1 == 0)
                {
                    printf("%i\tp%i\t%i\n", co, p[mi].name, co + p[mi].rem);
                    co += p[mi].rem;
                    p[mi].rem = 0;
                    p[mi].comp = co;
                    gannli = co;

                    for (int y = 0; y < n; y++)
                        if (p[y].rem != 0)
                        {
                            mi = y;
                            break;
                        }
                }
            }
            else
            {
                co++;
                if (p[i].ari <= co)
                    printf("%i\tp-1\t%i\n", gannli, co);
            }
        }
        else
        {
            i++;
        }
    }
    display();
}
int main(int argc, char const *argv[])
{
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &p[i].ari);
        scanf("%i", &p[i].bur);
        // scanf("%i", &p[i].prio);
    }
    rb();
    // fcfs();
    // sjf();
    // srtf();
    return 0;
}
