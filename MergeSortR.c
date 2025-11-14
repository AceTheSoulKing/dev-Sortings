#include <stdio.h>

void merge(int A[], int l, int m, int h)
{
    int i = l, j = m + 1;
    int k = l;
    int B[30];

    while (i <= m && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else if (A[j] < A[i])
            B[k++] = A[j++];
        else
            B[k++] = A[i++];
    }

    for (; i <= m; i++)
        B[k++] = A[i];

    for (; j <= h; j++)
        B[k++] = A[j];

    for (int y = l; y <= h; y++)
        A[y] = B[y];
}

void mergeSortR(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSortR(A, l, mid);
        mergeSortR(A, mid + 1, h);
        merge(A, l, mid, h);
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
    int A[] = {100, 20, 500, 3, 10, 50};

    int B[] = {1, 2, 3, -10, -5, -40};

    mergeSortR(A, 0, 5);
    display(A, 6);

    mergeSortR(B, 0, 5);
    display(B, 6);
}