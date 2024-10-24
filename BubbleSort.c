#include <stdio.h>

void BubbleSort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

void BetterBubbleSort(int array[], int size)
{
    int flag = 1;
    for(int i = 0; i < size - 1; i++)
    {

        flag = 1;
        for(int j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                flag = 0;
            }
        }
        if(flag)
        {
            return;
        }
    }
}
