#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int files[100],
    fil[6][2];
struct fia
{
    int st;
    int no;
    int bl[20];
} fi[100];
void in()
{
    int i, j;
    for (i = 0; i < 100; i++)
        files[i]=0;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 2; j++)
        {
            fil[i][j] = 0;
        }
    }
    for (i = 0; i < 100; i++)
    {
        fi[i].st = 0;
        fi[i].no = 0;
        for (int k = 0; k < 20; k++)
        {
            fi[i].bl[k] = 0;
        }
    }
}
void seq()
{
    int n, i, stin, le, co = 0, j;
    in();
    printf("Enter the number of files\n");
    scanf("%i", &n);
    for (i = 0; i < n; i++)
    {
        co = 0;
        printf("\nFile %i\n", i + 1);
        printf("Enter the starting block\n");
        scanf("%i", &stin);
        printf("Enter the number of block\n");
        scanf("%i", &le);
        for (j = stin; j < (stin + le); j++)
        {
            if (files[j] == 0)
            {
                co++;
                files[j] = 1;
            }
        }
        if (co == le)
        {
            printf("The file %i is allocated to the disk\n", i + 1);
            fil[i][0] = stin;
            fil[i][1] = le;
        }
        else
        {
            printf("The file %i cannot allocate to the disk\n\n", i + 1);
            fil[i][0] = -1;
            fil[i][1] = -1;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (fil[i][0] == -1)
        {
            printf("\nFilename:%i Cannot be allocated\n", i + 1);
        }
        else
        {
            printf("\nFilename:%i Startblock:%i  Length:%i\n", i + 1, fil[i][0], fil[i][1]);
        }
    }
    printf("\n");
}
void lin()
{
    in();
    int i, j, n;
    printf("Enter the number of files\n");
    scanf("%i", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nFile %i\n", i + 1);
        printf("Enter starting block \n");
        scanf("%i", &fi[i].st);
        printf("Enter number of blocks\n");
        scanf("%i", &fi[i].no);
        printf("Enter the blocks\n");
        for (j = 0; j < fi[i].no; j++)
        {
            scanf("%i", &fi[i].bl[j]);
        }
        if (files[fi[i].st] == 1)
        {
            printf("\nFile %i cannot be allocated\n", i + 1);
            fi[i].bl[0] = -1;
            continue;
        }
        else
        {
            files[fi[i].st] = 1;
        }
        for (j = 0; j < fi[i].no; j++)
        {
            if (files[fi[i].bl[j]] == 1)
            {
                printf("In file%i, block %i cannot allocate \n", i + 1, fi[i].bl[j]);
                for (int u = 0; u <= j; u++)
                {
                    fi[i].bl[u] = -1;
                }
                break;
            }
            else
            {
                files[fi[i].bl[j]] = 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (fi[i].bl[0] == -1)
        {
            printf("\nFile %i cannot be allocated\n", i + 1);
        }
        else
        {
            printf("\nFilename:%i ", i + 1);
            printf("Startblock:%i ", fi[i].st);
            printf("Size:%i ", fi[i].no);
            printf("Blocks: ");
            for (j = 0; j < fi[i].no - 1; j++)
            {
                printf("%i->", fi[i].bl[j]);
            }
            printf("%i\n", fi[i].bl[j]);
        }
    }
    printf("\n");
}
void ind()
{
    in();
    int i, j, n;
    printf("Enter the number of files\n");
    scanf("%i", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nFile %i\n", i + 1);
        printf("Enter Index block \n");
        scanf("%i", &fi[i].st);
        printf("Enter number of blocks\n");
        scanf("%i", &fi[i].no);
        printf("Enter the blocks\n");
        for (j = 0; j < fi[i].no; j++)
        {
            scanf("%i", &fi[i].bl[j]);
        }
        if (files[fi[i].st] == 1)
        {
            printf("\nFile %i cannot be allocated\n", i + 1);
            fi[i].bl[0] = -1;
            continue;
        }
        else
        {
            files[fi[i].st] = 1;
        }
        for (j = 0; j < fi[i].no; j++)
        {
            if (files[fi[i].bl[j]] == 1)
            {
                printf("In file%i, block %i cannot allocate \n", i + 1, fi[i].bl[j]);
                for (int u = 0; u <= j; u++)
                {
                    fi[i].bl[u] = -1;
                }
                break;
            }
            else
            {
                files[fi[i].bl[j]] = 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (fi[i].bl[0] == -1)
        {
            printf("\nFilename%i: cannot be allocated\n", i + 1);
        }
        else
        {
            printf("\nFilename:%i ", i + 1);
            printf("Index Block:%i ", fi[i].st);
            printf("Length:%i ", fi[i].no);
        }
    }
    printf("\n");
}

int main()
{
    int c;
    while (1)
    {
        printf("1.Sequential\n");
        printf("2.Index\n");
        printf("3.Linked\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%i", &c);
        switch (c)
        {
        case 1:
            seq();
            break;
        case 2:
            ind();
            break;
        case 3:
            lin();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a correct option\n");
            break;
        }
    }
}