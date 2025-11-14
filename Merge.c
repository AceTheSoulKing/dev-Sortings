#include <stdio.h>

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1;
    int k = l;
    int B[h + 1];

    while (i <= mid && j < h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else if (A[j] < A[i])
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];

    for (; j <= h; j++)
        B[k++] = A[j];

    for (int y = 0; y < h; y++)
        A[y] = B[y];
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
    int A[] = {2, 12, 5, 10, 1, 3};

    merge(A, 0, 2, 6);
    display(A, 6);
}