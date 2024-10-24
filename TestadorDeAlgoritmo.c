#include <stdio.h>
#include <time.h>
#include <string.h>
#include "BubbleSort.h"
#include "QuickSort.h"

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

void load_random_array(int array[], int size, int i)
{
    FILE *file = NULL;
    char directory_name[50] = ".\\CasoDeTeste\\Aleatorio";

    char ID[4];
    itoa(i, ID,10);
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

        //BubbleSort(array, size);
        //mudar algoritimo
        clock_t start = clock();
        BetterBubbleSort(array, size);
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

    return 0;
}
