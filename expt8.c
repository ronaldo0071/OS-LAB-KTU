#include <stdio.h>
#include <stdlib.h>
void print(int x[][10], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < m; j++)
        {
            printf("%d\t", x[i][j]);
        }
    }
}
void res_request(int A[10][10], int N[10][10], int AV[10][10], int pid, int m)
{
    int reqmat[1][10];
    int i;
    printf("\n Enter additional request :- \n");
    /*for(i=0;i<m;i++){
printf(" Request for resource %d : ",i+1);
scanf("%d",&reqmat[0][i]);
}*/
    printf(" Request for resource A B C D : ");
    scanf("%d %d %d %d", &reqmat[0][0], &reqmat[0][1], &reqmat[0][2], &reqmat[0][3]);
    for (i = 0; i < m; i++)
        if (reqmat[0][i] > N[pid][i])
        {
            printf("\n Error encountered.\n");
            exit(0);
        }
    for (i = 0; i < m; i++)
        if (reqmat[0][i] > AV[0][i])
        {
            printf("\n Resources unavailable.\n");
            exit(0);
        }
    for (i = 0; i < m; i++)
    {
        AV[0][i] -= reqmat[0][i];
        A[pid][i] += reqmat[0][i];
        N[pid][i] -= reqmat[0][i];
    }
}

int safety(int A[][10], int N[][10], int AV[1][10], int n, int m, int a[], int b[], int c[], int kk, int kkk)
{
    int i, j, k, x = 0, d;
    int F[10], W[1][10];
    int pflag = 0, flag = 0;
    for (i = 0; i < n; i++)
        F[i] = 0;
    for (i = 0; i < m; i++)
        W[0][i] = AV[0][i];
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (F[i] == 0)
            {
                flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (N[i][j] > W[0][j])
                        flag = 1;
                }
                if (flag == 0 && F[i] == 0)
                {
                    for (j = 0; j < m; j++)
                        W[0][j] += A[i][j];
                    F[i] = 1;
                    pflag++;
                    a[x++] = i;
                }
            }
        }
        if (pflag == n)
            d = 1;
    }
    if (pflag != n)
        d = 0;
    pflag = 0;
    flag = 0;
    x = 0;
    for (i = 0; i < n; i++)
        F[i] = 0;
    for (i = 0; i < m; i++)
        W[0][i] = AV[0][i];
    for (k = n - 1; k >= 0; k--)
    {
        for (i = n - 1; i >= 0; i--)
        {
            if (F[i] == 0)
            {
                flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (N[i][j] > W[0][j])
                        flag = 1;
                }
                if (flag == 0 && F[i] == 0)
                {
                    for (j = 0; j < m; j++)
                        W[0][j] += A[i][j];
                    F[i] = 1;
                    pflag++;
                    b[x++] = i;
                }
            }
        }
        if (pflag == n)
            kk = 1;
    }
    if (pflag != n)
        kk = 0;
    pflag = 0;
    flag = 0;
    x = 0;
    for (i = 0; i < n; i++)
        F[i] = 0;
    for (i = 0; i < m; i++)
        W[0][i] = AV[0][i];
    for (k = n - 1; k >= 0; k--)
    {
        for (i = n - 1; i >= 0; i--)
        {
            if (F[i] == 0)
            {
                flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (N[i][j] > W[0][j])
                        flag = 1;
                }
                if (flag == 0 && F[i] == 0)
                {
                    for (j = 0; j < m; j++)
                        W[0][j] += A[i][j];
                    F[i] = 1;
                    pflag++;
                    c[x++] = i;
                    break;
                }
            }
        }
        if (pflag == n)
            kkk = 1;
    }
    if (pflag != n)
        kkk = 0;
    if (d == 1)
        return 1;
    else
        return 0;
}

void accept(int A[][10], int N[][10], int M[10][10], int W[1][10], int *n, int *m)
{
    int i, j;
    printf("\n Enter total no. of processes : ");
    scanf("%d", n);
    printf("\n Enter total no. of resources : ");
    scanf("%d", m);
    for (i = 0; i < *n; i++)
    {
        printf("\n Process %d\n", i);
        printf(" Allocation for resource A B C D : ");
        scanf("%d %d %d %d", &A[i][0], &A[i][1], &A[i][2], &A[i][3]);
        printf(" Maximum for resource A B C D : ");
        scanf("%d %d %d %d", &M[i][0], &M[i][1], &M[i][2], &M[i][3]);
    }
    printf("\n Available resources : \n");
    /*for(i=0;i<*m;i++){
printf(" Resource %d : ",i+1);
scanf("%d",&W[0][i]);
}*/
    scanf("%d %d %d %d", &W[0][0], &W[0][1], &W[0][2], &W[0][3]);
    for (i = 0; i < *n; i++)
        for (j = 0; j < *m; j++)
            N[i][j] = M[i][j] - A[i][j];
    printf("\n Allocation Matrix");
    print(A, *n, *m);
    printf("\n Maximum Requirement Matrix");
    print(M, *n, *m);
    printf("\n Need Matrix");
    print(N, *n, *m);
}
int banker(int A[][10], int N[][10], int W[1][10], int n, int m)
{
    int j, i, a[10], b[10], c[10], kk, kkk;
    j = safety(A, N, W, n, m, a, b, c, kk, kkk);
    if (j != 0)
    {
        printf("\n\n");
        for (i = 0; i < n; i++)
            printf(" P%d ", a[i]);
        printf("\n A safety sequence has been detected.\n");
        if (kk != 0)
        {
            printf("\n\n");
            for (i = 0; i < n; i++)
                printf(" P%d ", b[i]);
        }
        if (kkk != 0)
        {
            printf("\n\n");
            for (i = 0; i < n; i++)
                printf(" P%d ", c[i]);
        }
        return 1;
    }
    else
    {
        printf("\n Deadlock has occured.\n");
        return 0;
    }
}
int main()
{
    int ret;
    int A[10][10];
    int M[10][10];
    int N[10][10];
    int W[1][10];
    int n, m, pid, ch;
    accept(A, N, M, W, &n, &m);
    ret = banker(A, N, W, n, m);
    if (ret != 0)
    {
        while (1)
        {
            printf("\n Do you want make an additional request ? (1=Yes|0=No)");
            scanf("%d", &ch);
            if (ch == 1)
            {
                printf("\n Enter process no. : ");
                scanf("%d", &pid);
                res_request(A, N, W, pid, m);
                ret = banker(A, N, W, n, m);
                if (ret == 0)
                    exit(0);
            }
            else
            {
                break;
            }
        }
    }
    else
        exit(0);
    return 0;
}