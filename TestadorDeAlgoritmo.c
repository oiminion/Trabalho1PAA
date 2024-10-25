#include <stdio.h>
#include <time.h>
#include <string.h>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "InsertionSort.h"

enum ORDER
{
    ascending,
    descending,
    randomm
};

void load_ascending_array(int array[], int size)
{
    FILE *file = NULL;
    char directory_name[50] = ".\\CasoDeTeste\\Crescente_";
    strcat(directory_name, "50000");
    strcat(directory_name, ".dat\0");

    if(file = fopen(directory_name,"rb"))
    {
        fread(array,sizeof(int),size,file);
        fclose(file);
    }
}

void load_descending_array(int array[], int size)
{
    FILE *file = NULL;
    char directory_name[50] = ".\\CasoDeTeste\\Decrescente_";
    strcat(directory_name, "50000");
    strcat(directory_name, ".dat\0");

    if(file = fopen(directory_name,"rb"))
    {
        fread(array,sizeof(int),size,file);
        fclose(file);
    }
}

void convert_int_str(int number, char string[])
{
    int i = 0;
    while(number > 0)
    {
        string[i++] = number % 10 + '0';
        number /= 10;
    }

    string[i] == '\0';

    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char aux = string[j];
        string[j] = string[k];
        string[k] = aux;
    }
}

void load_random_array(int array[], int size, int i)
{
    FILE *file = NULL;
    char directory_name[50] = ".\\CasoDeTeste\\Aleatorio";

    char ID[4];
    convert_int_str(i, ID);
    strcat(directory_name, ID);
    strcat(directory_name, "_");
    strcat(directory_name, "50000");
    strcat(directory_name, ".dat\0");

    if(file = fopen(directory_name,"rb"))
    {
        fread(array,sizeof(int),size,file);
        fclose(file);
    }
}

int main()
{
    int size = 50000;
    enum ORDER order = randomm;

    int test_quantity = 100;
    int array[size];

    int flag = 1;
    int error = -1;

    double test_time[test_quantity];
    int counter = 0;

    for(int i = 0; i < test_quantity; i++)
    {
        if(order == ascending)
        {
            load_ascending_array(array, size);
        }
        else if(order == descending)
        {
            load_descending_array(array, size);
        }
        else if(order == randomm)
        {
            load_random_array(array, size, i+1);
        }

        //BubbleSort(array, size);
        //MergeSort(array, size);
        //HeapSort(array, size);
        //SelectionSort(array,size);
        //ShellSort(array,size);
        //InsertionSort(array,size);
        //mudar algoritimo

        clock_t start = clock();
        HeapSort(array,size);
        clock_t end = clock();


        for(int j = 0; j < size - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                flag = 0;
                error = i;
                break;
            }
        }

        if(error != -1)break;

        double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
        test_time[i] = elapsed;
    }

    double result = 0;
    for(int i = 0; i < test_quantity; i++)
    {
        result += test_time[i];
    }

    result = (double)result/test_quantity;

    if(error == -1)
    {
        printf("media: %lf\n",result);
    }
    else
    {
        printf("flag: %d\n",flag);
        printf("error: %d\n",error);
    }

    printf("%d",array[49999]);

    return 0;
}
