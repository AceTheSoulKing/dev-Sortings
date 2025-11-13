#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[], int size)
{
    int flag; // used for breaking the loop if list is already sorted
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("List is already sorted\n");
            break;
        }
    }
}

void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\t", A[i]);
    printf("\n");
}

int main()
{
    int A[5] = {10, 3, 2, 9, 15};

    bubbleSort(A, 5);
    display(A, 5);
}