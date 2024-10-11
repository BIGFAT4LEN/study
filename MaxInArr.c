//нахождение максимального числа в массиве
#include <stdio.h>
#include <stdlib.h>
//функция нахождения максимального элемента в массиве
float FindMax(float *arr, int count)
{

    float max = arr[0];
    for (int i = 1 ; i < count; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}


int main()
{
    int max = 0;
    int count = 0;
    float *arr = NULL;
    printf(" ");
    scanf("%d", &count);
    arr = (float *)malloc(count*sizeof(float));
    max = FindMax(arr, count);
    printf("%d\n", max);
    return 0;
}
