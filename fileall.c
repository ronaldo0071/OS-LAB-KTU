#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int memory[100], fil[6][2];
struct fia
{
    int st;
    int no;
    int vis;
    int bl[20];
    struct node *k;
} fi[100];
struct node
{
    int n;
    struct node *next;
} * head;
void in()
{
    int i, j;
    for (i = 0; i < 100; i++)
        memory[i] = 0;
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
        fi[i].vis = 0;
        for (int k = 0; k < 20; k++)
        {
            fi[i].bl[k] = 0;
        }
        fi[i].k = NULL;
    }
}
void seq()
{
    int n, i, stin, le, co = 0, j, flag;
    in();
    printf("Enter the number of files\n");
    scanf("%i", &n);
    for (i = 0; i < n; i++)
    {
        co = 0;
        flag = 0;
        printf("\nFile %i\n", i + 1);
        printf("Enter the starting block\n");
        scanf("%i", &fi[i].st);
        printf("Enter Length\n");
        scanf("%i", &fi[i].no);
        for (j = fi[i].st; j < (fi[i].st + fi[i].no); j++)
        {
            if (memory[j] == 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("The file %i is allocated to the disk\n", i + 1);
            fi[i].vis = 1;
            for (j = stin; j < (stin + le); j++)
            {
                memory[j] = 1;
            }
        }
        else{
            printf("\nFilename:%i Cannot be allocated\n", i + 1);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (fi[i].vis == 0)
        {
            printf("\nFilename:%i Cannot be allocated\n", i + 1);
        }
        else
        {
            printf("\nFilename:%i Startblock:%i  Length:%i\n", i + 1, fi[i].st, fi[i].no);
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
        int flag = 0;
        printf("\nFile %i\n", i + 1);
        printf("Enter starting block \n");
        scanf("%i", &fi[i].st);
        if (memory[fi[i].st] == 1)
        {
            printf("\nFile %i cannot be allocated\n", i + 1);
            fi[i].k = NULL;
            continue;
        }
        else
        {
            memory[fi[i].st] = 1;
        }
        printf("Enter number of blocks\n");
        scanf("%i", &fi[i].no);
        printf("Enter the blocks\n");
        struct node *temp, *t;
        int te;
        for (j = 0; j < fi[i].no; j++)
        {
            t = (struct node *)malloc(sizeof(struct node));
            scanf("%i", &te);
            if (memory[te] == 1)
            {
                printf("In file%i, block %i cannot allocate \n", i + 1, temp->n);
                fi[i].k = NULL;
                flag = 1;
                break;
            }
            t->n = te;
            t->next = NULL;
            if (fi[i].k == NULL)
            {
                fi[i].k = t;
            }
            else
            {
                temp = fi[i].k;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = t;
            }
        }
        temp = fi[i].k;
        while (temp != NULL)
        {
            if (memory[temp->n] == 1)
            {
                printf("In file%i, block %i cannot allocate \n", i + 1, temp->n);
                fi[i].k = NULL;
                break;
            }
            else
            {
                memory[temp->n] = 1;
            }
            temp = temp->next;
        }
    }

    for (i = 0; i < n; i++)
    {
        struct node *temp;
        if (fi[i].k == NULL)
        {
            printf("\nFile %i cannot be allocated\n", i + 1);
        }
        else
        {
            printf("\nFilename:%i ", i + 1);
            printf("Startblock:%i ", fi[i].st);
            printf("Size:%i ", fi[i].no);
            printf("Blocks: ");
            temp = fi[i].k;
            while (temp->next != NULL)
            {
                printf("%i->", temp->n);
                temp = temp->next;
            }
            printf("%i\n", temp->n);
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
        int flag = 0;
        printf("\nFile %i\n", i + 1);
        printf("Enter Index block \n");
        scanf("%i", &fi[i].st);
        if (memory[fi[i].st] == 1)
        {
            printf("\nFile %i cannot be allocated\n", i + 1);
            fi[i].bl[0] = -1;
            continue;
        }
        else
        {
            memory[fi[i].st] = 1;
        }
        printf("Enter number of blocks\n");
        scanf("%i", &fi[i].no);
        printf("Enter the blocks\n");
        for (j = 0; j < fi[i].no; j++)
        {
            scanf("%i", &fi[i].bl[j]);
            if (memory[fi[i].bl[j]] == 1)
            {
                flag = 1;
                fi[i].vis = 0;
                fi[i].bl[0] = -1;
                break;
            }
        }
        if(flag == 0){
            for (j = 0; j < fi[i].no; j++)
            {
                fi[i].vis = 1;
                memory[fi[i].bl[j]] = 1;
            }
        }
        else{
            printf("\nFile %i cannot be allocated\n", i + 1);
        }
    }

    for (i = 0; i < n; i++)
    {
        if (fi[i].bl[0] == -1)
        {
            printf("\nFilename:%i cannot be allocated\n", i + 1);
        }
        else
        {
            printf("\nFilename:%i ", i + 1);
            printf("Indexblock:%i ", fi[i].st);
            printf("Length:%i \n", fi[i].no);
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