#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Next;
};

void insert(struct Node **p, int data)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = data;
    q->Next = NULL;

    // If bucket empty — new head
    if (*p == NULL)
    {
        *p = q;
    }
    else
    {
        struct Node *t = *p;
        while (t->Next != NULL)
            t = t->Next;
        t->Next = q;
    }
}

int Delete(struct Node **p)
{
    struct Node *q = *p;
    int deleted = q->data;

    *p = q->Next; // Move head forward
    free(q);

    return deleted;
}

int findMax(int A[], int size)
{
    int max = A[0];
    for (int i = 1; i < size; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

void bucketSort(int A[], int size)
{
    int max = findMax(A, size);

    struct Node **Bin = (struct Node **)malloc(sizeof(struct Node *) * (max + 1));

    for (int i = 0; i <= max; i++)
        Bin[i] = NULL;

    // Insert each element into its bucket
    for (int j = 0; j < size; j++)
        insert(&Bin[A[j]], A[j]);

    int i = 0, j = 0;

    // Extract elements in sorted order
    while (i <= max)
    {
        while (Bin[i] != NULL)
            A[j++] = Delete(&Bin[i]);
        i++;
    }

    free(Bin);
}

void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\t", A[i]);
    printf("\n");
}

int main()
{
    int A[] = {100, 1, 50, 3, 2};

    bucketSort(A, 5);
    display(A, 5);
}
