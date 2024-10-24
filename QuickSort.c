#include <stdio.h>

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
        while(array[i] <= pivot && i <= ceiling - 1)
        {
            i++;
        }

        while(array[j] > pivot && j >= bottom + 1)
        {
            j--;
        }
        if(i < j)
        {
            change(&array[i], &array[j]);
        }
    }
    change(&array[bottom], &array[j]);
    return j;
}

void QuickSortFirst(int array[], int bottom, int ceiling)
{
    if(bottom < ceiling)
    {
        int pivot_position = partitionFirst(array, bottom, ceiling);

        QuickSortFirst(array, bottom, pivot_position - 1);
        QuickSortFirst(array, pivot_position + 1, ceiling);
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
