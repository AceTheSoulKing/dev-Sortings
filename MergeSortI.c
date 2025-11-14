#include <stdio.h>

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1;
    int k = l;
    int B[h + 1];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else if (A[j] < A[i])
            B[k++] = A[j++];
        else
            B[k++] = A[i++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];

    for (; j <= h; j++)
        B[k++] = A[j];

    for (int y = l; y <= h; y++)
        A[y] = B[y];
}

void mergeSortI(int A[], int size)
{
    int p, i, l, m, h;

    for (p = 2; p <= size; p = p * 2)
    {
        for (i = 0; i + p - 1 < size; i += p)
        {
            l = i;
            h = i + p - 1;
            m = (l + h) / 2;
            merge(A, l, m, h);
        }
    }

    if ((p / 2) < size)
        merge(A, 0, (p / 2) - 1, size - 1);
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
    int A[] = {3, 4, 10, 5, 12, 5};

    display(A, 6);

    mergeSortI(A, 6);
    display(A, 6);
}
