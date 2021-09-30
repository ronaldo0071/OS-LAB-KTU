#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 10
struct item
{
    char arr[100];
};

struct item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int p = 1;
int count = 0;

void prod(int n)
{
    count = 0;
    struct item next_produced;
    for (int j = 1; j <= n; j++)
    {
        if (((in + j) % BUFFER_SIZE) == out)
        {
            printf("Cant produce\n");
            return;
        }
    }
    for (int j = 0; j < n; j++)
    {
        //if(((in + 1) % BUFFER_SIZE) != out){
        count++;
        printf("Enter the name of the item to be produced : ");
        scanf("%s", &next_produced.arr);
        buffer[in] = next_produced;
        in = (in + 1) % BUFFER_SIZE;
        //}
    }
}

void cons()
{
    struct item next_consumed;
    //next_consumed = buffer[in];
    if (in != out)
    {
        // count--;
        next_consumed = buffer[out];
        printf("Consumer consumes %s\n", buffer[out].arr);
        out = (out + 1) % BUFFER_SIZE;
    }
    else
    {
        printf("Cant consume\n");
        return;
    }
}

void display()
{
    if (in != out)
    {
        printf("\nThe items in the buffer : ");
        for (int i = out; i != in; i = (i + 1) % BUFFER_SIZE)
        {
            printf("%s ", buffer[i].arr);
        }
    }
    else
    {
        printf("Empty buffer\n");
    }
}

void main()
{
    int op, q;
    while (1)
    {
        printf("\n\nEnter a value\n");
        printf("Options are :\n1.Produce\n2.Consume\n0.Exit\n");
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            printf("Enter the number of items to be produced\n");
            scanf("%i", &q);
            prod(q);
            printf("\nProducer produces %d items\n", count);
            display();
            break;
        case 2:
            cons();
            display();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Enter valid option\n");
            break;
        }
    }
}