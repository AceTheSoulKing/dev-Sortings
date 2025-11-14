#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int A[], int size)
{
    int i, j, k;
    for (i = 0; i < size; i++)
    {
        for (j = k = i; j < size; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
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
    int A[] = {19, 3, 6, 21, 5};

    int B[] = {3, 4, 5, 6, 7};

    selectionSort(A, 5);
    display(A, 5);

    selectionSort(B, 5);
    display(B, 5);
}