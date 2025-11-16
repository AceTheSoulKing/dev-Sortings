#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Next;
};

int LdigitCount(int A[], int size)
{
    int Max = A[0];
    for (int i = 1; i < size; i++)
        if (A[i] > Max)
            Max = A[i];

    int Count = 0;

    while (Max > 0)
    {

        Max = Max / 10;
        Count++;
    }

    return Count;
}

void insert(struct Node **p, int data)
{
    struct Node *t = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->Next = NULL;

    if (*p == NULL)
    {
        *p = t;
    }
    else
    {
        struct Node *q = *p;
        while (q->Next != NULL)
            q = q->Next;
        q->Next = t;
    }
}

int Delete(struct Node **p)
{
    int deleted;
    struct Node *t = *p;

    deleted = t->data;
    *p = t->Next;
    free(t);

    return deleted;
}

void radixSort(int A[], int size)
{
    int maxDigit;
    maxDigit = LdigitCount(A, size);

    struct Node **Bin;
    Bin = (struct Node **)malloc(sizeof(struct Node *) * 10);

    for (int i = 0; i < 10; i++)
        Bin[i] = NULL;

    int exp = 1;

    for (int i = 0; i < maxDigit; i++)
    {
        for (int j = 0; j < size; j++)
        {
            insert(&Bin[(A[j] / exp) % 10], A[j]);
        }

        int m = 0, n = 0;

        while (m < 10)
        {
            while (Bin[m] != NULL)
                A[n++] = Delete(&Bin[m]);
            m++;
        }

        for (int i = 0; i < 10; i++)
            Bin[i] = NULL;

        exp *= 10;
    }

    free(Bin);
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
    int A[] = {10, 20, 19, 18, 1};

    radixSort(A, 5);
    display(A, 5);
}