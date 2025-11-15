#include <stdio.h>
#include <stdlib.h>
int findMax(int A[], int size)
{
    int currentMax = 0;
    int i = 0;

    while (i < size)
    {
        if (A[i] > currentMax)
        {
            currentMax = A[i];
            i++;
        }
        else
            i++;
    }

    return currentMax;
}

void countSort(int A[], int size)
{
    int i, j, max;
    max = findMax(A, size);
    int *B;

    B = (int *)malloc(sizeof(int) * max + 1);

    for (i = 0; i < max + 1; i++)
        B[i] = 0;

    for (j = 0; j < size; j++)
        B[A[j]]++;

    i = 0, j = 0;

    while (i < max + 1)
    {
        if (B[i] > 0)
        {
            A[j++] = i;
            B[i]--;
        }
        else
            i++;
    }
}

void display(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d\t", A[i]);
    printf("\n");
}

int main()
{
    int A[] = {10, 3, 3, 5, 2, 3, 1};

    int B[] = {1, 2, 3, 4, 5, 6, 7};

    countSort(A, 7);
    display(A, 7);

    countSort(B, 7);
    display(B, 7);
}