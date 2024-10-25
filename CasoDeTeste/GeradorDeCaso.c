#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEBUG 0

enum ORDER
{
    ascending,
    descending,
    randomm
};

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

void shuffle(int array[], int size)
{
    int aux1, aux2, aux3;
    for(unsigned long int i = 0; i < size; i++)
    {
        for(unsigned long int j = 0; j < size; j++){
            aux1 = rand() % size;
            aux2 = rand() % size;
            while(aux1 == aux2)
            {
                aux2 = rand() % size;
            }
            aux3 = array[aux1];
            array[aux1] = array[aux2];
            array[aux2] = aux3;
        }
    }
}

void print_array(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\n",array[i]);
    }
}

int CreateCase(int array[], int size, enum ORDER order, int quantity)
{
    char format[] = ".dat\0";
    char aux[10];
    sprintf(aux , "%d\0", size);
    if(order == ascending)
    {
        for(int i = 1; i <= size; i++)
        {
            array[i-1] = i;
        }

        FILE *file = NULL;

        char directory_name[50] = "Crescente_";
        strcat(directory_name, aux);
        strcat(directory_name, format);

        if(DEBUG)
        {
            printf("Crescente:\n");
            print_array(array, size);
        }

        if(file = fopen(directory_name,"wb"))
        {
            fwrite(array, sizeof(int), size, file);

            fclose(file);
            return 1;
        }
    }
    else if(order == descending)
    {
        for(int i = size; i >= 0; i--)
        {
            array[size - i] = i;
        }

        FILE *file = NULL;

        char directory_name[50] = "Decrescente_";
        strcat(directory_name, aux);
        strcat(directory_name, format);

        if(DEBUG)
        {
            printf("Decrescente:\n");
            print_array(array, size);
        }

        if(file = fopen(directory_name,"wb"))
        {
            fwrite(array, sizeof(int), size, file);

            fclose(file);
            return 1;
        }
    }
    else
    {
        for(int i = 1; i <= quantity; i++)
        {
            shuffle(array, size);
            FILE *file = NULL;
            char directory_name[50] = "Aleatorio";

            char ID[4];
            sprintf(ID, "%d\0", i);

            strcat(directory_name, ID);
            strcat(directory_name, "_");
            strcat(directory_name, aux);
            strcat(directory_name, format);

            if(DEBUG)
            {
                printf("rand %d\n",i);
                print_array(array, size);
            }

            if(file = fopen(directory_name,"wb"))
            {
                fwrite(array, sizeof(int), size, file);

                fclose(file);
            }
        }
    }

    return 0;
}

int main()
{
    int size = 100000;
    int random_order_quantity = 100;

    srand(time(0));

    int *array = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++)
    {
        array[i] = i;
    }

    CreateCase(array, size, ascending, random_order_quantity);
    CreateCase(array, size, descending, random_order_quantity);
    CreateCase(array, size, randomm, random_order_quantity);

    return 0;
}
