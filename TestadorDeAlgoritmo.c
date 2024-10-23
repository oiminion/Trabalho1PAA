#include <stdio.h>
#include <time.h>
#include "BubbleSort.h"

enum ORDER
{
    ascending,
    descending,
    random
};

void load_ascending_array(int array[], int size)
{
    FILE *file = NULL;
    char directory_name[50] = ".\\CasoDeTeste\\Crescente_";
    char aux[10];
    itoa(size, aux,10);
    strcat(directory_name, aux);
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
    char aux[10];
    itoa(size, aux,10);
    strcat(directory_name, aux);
    strcat(directory_name, ".dat\0");

    if(file = fopen(directory_name,"rb"))
    {
        fread(array,sizeof(int),size,file);
        fclose(file);
    }
}

void load_random_array(int array[], int size, int i)
{
    FILE *file = NULL;
    char directory_name[50] = ".\\CasoDeTeste\\Aleatorio";

    char ID[3];
    itoa(i, ID,10);
    char aux[10];
    itoa(size, aux,10);

    strcat(directory_name, ID);
    strcat(directory_name, "_");
    strcat(directory_name, aux);
    strcat(directory_name, ".dat\0");

    if(file = fopen(directory_name,"rb"))
    {
        fread(array,sizeof(int),size,file);
        fclose(file);
    }
}

int main()
{
    int size = 10000;
    enum ORDER order = random;
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
        else if(order == random)
        {
            load_random_array(array, size, i+1);
        }

        clock_t start = clock();
        BubbleSort(array, size);
        clock_t end = clock();

        for(int j = 0; j < size - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                flag = 0;
                error = i;
            }
        }

        double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
        test_time[i] = elapsed;
    }

    printf("flag: %d\n",flag);
    printf("error: %d\n",error);

    double result = 0;
    for(int i = 0; i < test_quantity; i++)
    {
        result += test_time[i];
    }
    result = (double)result/test_quantity;
    printf("media: %lf\n",result);



    return 0;
}
