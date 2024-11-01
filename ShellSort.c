
int pow(int num, int exp)
{
    int result = 1;
    for(int i = 0; i < exp; i++)
    {
        result *= num;
    }
    return result;
}

void ShellSort(int array[], int size) {
    int i, j, value;
    int k = 1;

    while(pow(2,k) - 1 < size) {
        k++;
    }
    k--;
    for(k; k > 0; k--)
    {
        int gap = pow(2,k) - 1;
        for(int i = gap; i < size; i++)
        {
            int value = array[i];
            for(j = i; j >= gap && array[j - gap] > value; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = value;
        }
    }
}
