#include <stdio.h>

void shellSort(int A[], int size)
{
    int gap, i, j, temp;

    for (gap = size / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
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
    int A[] = {9, 5, 16, 8, 13, 6, 12, 10, 4, 2, 3};

    shellSort(A, 11);
    display(A, 11);
}