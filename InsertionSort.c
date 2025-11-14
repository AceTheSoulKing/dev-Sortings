#include <stdio.h>

void insertionSort(int A[], int size)
{
    int i, j;
    int x;

    for (i = 1; i < size; i++)
    {
        j = i - 1;
        x = A[i];

        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
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
    int A[] = {10, 5, 4, 3, 2, 1};

    int B[] = {10, 20, 30, 40, 50};

    insertionSort(A, 6);
    display(A, 6);

    insertionSort(B, 5);
    display(B, 5);
}