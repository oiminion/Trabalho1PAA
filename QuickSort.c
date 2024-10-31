#include <stdio.h>

typedef struct Partition{
    int bottom;
    int ceiling;
}PARTITION;

typedef struct Node{
    PARTITION partition;
    struct node* down;
}NODE;

typedef struct Stack{
    NODE *top;
}STACK;

void insertStack(STACK *stack, int bottom, int ceiling)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->partition.bottom = bottom;
    new_node->partition.ceiling = ceiling;
    new_node->down = stack->top;
    stack->top = new_node;
}

PARTITION popStack(STACK *stack)
{
    PARTITION result;
    result.bottom = stack->top->partition.bottom;
    result.ceiling = stack->top->partition.ceiling;

    NODE *aux = stack->top;
    stack->top = stack->top->down;

    free(aux);

    return result;
}

void change(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partitionFirst(int array[], int bottom, int ceiling)
{
    int pivot = array[bottom];
    int i = bottom;
    int j = ceiling;

    while(i < j)
    {
        while(array[i] <= pivot)
        {
            i++;
        }


        while(array[j] > pivot)
        {
            j--;
        }

        if(i < j)
        {
            change(&array[i], &array[j]);
        }
    }

    array[bottom] = array[j];
    array[j] = pivot;

    return j;
}

void QuickSortFirst(int array[], int size)
{
    STACK *stack = (STACK *)malloc(sizeof(STACK));
    stack->top = NULL;

    insertStack(stack, 0, size - 1);

    int bottom, ceiling;

    while(stack->top != NULL)
    {
        PARTITION aux = popStack(stack);
        bottom = aux.bottom;
        ceiling = aux.ceiling;

        int pivot_position = partitionFirst(array, bottom, ceiling);

        if(pivot_position - 1 > bottom)
        {
            insertStack(stack,bottom,pivot_position - 1);
        }
        if(pivot_position + 1 < ceiling)
        {
            insertStack(stack,pivot_position + 1, ceiling);
        }
    }
}

int partitionMiddle(int array[], int bottom, int ceiling)
{
    int pivot = array[(bottom + ceiling)/2];
    int i = bottom;
    int j = ceiling;

    while(i < j)
    {
        while(array[i] < pivot)
        {
            i++;
        }

        while(array[j] > pivot)
        {
            j--;
        }
        if(i < j)
        {
            change(&array[i], &array[j]);
        }
    }

    return j;
}

void QuickSortMiddle(int array[], int bottom, int ceiling)
{
    if(bottom < ceiling)
    {
        int pivot_position = partitionMiddle(array, bottom, ceiling);

        QuickSortMiddle(array, bottom, pivot_position - 1);
        QuickSortMiddle(array, pivot_position + 1, ceiling);
    }
}
