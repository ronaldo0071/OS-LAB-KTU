#include <stdio.h>
#include <stdlib.h>
int n, a[40], f, c;
void fifo()
{
    int frame[f];
    int fr[f][100], fi = 0;
    for (int i = 0; i < f; i++)
    {
        frame[i] = -1;
    }
    int count = 0, j = 0;
    //********* print the number ******
    for (int o = 0; o < f; o++)
        printf("Frame%i\t", o + 1);
    printf("\n");
    //*********************************
    for (int i = 0; i < n; i++)
    {
        int fcheck = 0;
        for (int k = 0; k < f; k++)
            if (a[i] == frame[k])
                fcheck = 1;
        if (fcheck)
        {
            int ui = 9;
        }
        else
        {
            frame[j] = a[i];

            j = (j + 1) % f;
            count++;
            fi++;
        }
        //*********************************
        for (int o = 0; o < f; o++)
        {
            if (frame[o] != -1)
                printf("%i\t", frame[o]);
            else
                printf("-\t");
        }
        printf("\n");
        //*********************************
    }

    printf("%i", count);
}

int main(int argc, char const *argv[])
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
    // fifo();
    optimal();
    return 0;
}
