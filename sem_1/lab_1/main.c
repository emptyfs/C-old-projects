#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
    
int index_first_negative(int[], int);
int index_last_negative(int[], int);
int sum_between_negative(int[], int);
int sum_before_and_after_negative(int[], int);

int main()
{
    int array[100];
    int N=0;
    int mode;
    char space;
    char checker[4];

    while(true)
    {
        N = 0;
        space = ' ';
        printf("%s\n", "Введите предпочитаемый режим (от 0 до 3)");
        scanf("%d", &mode);

        if (mode < 0 || mode > 3)
        {
            printf("Данные некорректны\n");
            continue;
        }

        printf("%s\n", "Введите массив чисел через пробел (максимальная длина массива - 100)");
        while(space != '\n') 
        {
            scanf("%d%c", &array[N], &space);
            N++;
        }
    
        switch(mode)  
        {
            case 0:
                printf("%d\n", index_first_negative(array, N));
                break; 
            case 1:
                printf("%d\n", index_last_negative(array, N));
                break;
            case 2:
                printf("%d\n", sum_between_negative(array, N));
                break;
            case 3:
                printf("%d\n", sum_before_and_after_negative(array, N));
                break;
        }

        printf("%s\n", "Закончить работу? (yes\\no)");
        fgets(checker, sizeof(checker), stdin);
        if (strcmp(checker, "yes") == 0)
        {
            break;
        }
    }
    return 0;
} 

int index_first_negative(int arr[], int len) 
{
    for (int i=0; i < len; i++) 
    {
        if (arr[i] < 0) 
        {
           return i;
        } 
     }
     return -1;
}

int index_last_negative(int arr[], int len) 
{
    for (int i = len-1; i >= 0; i--) 
    {
        if (arr[i] < 0) 
        {
           return i;
        } 
    }
     return -1;
}

int sum_between_negative(int arr[], int len) 
{
    int sum_negative = 0;
    for (int i = index_first_negative(arr, len); i < index_last_negative(arr, len); i++) 
    {
        sum_negative += abs(arr[i]);
    }
    return sum_negative;
}

int sum_before_and_after_negative(int arr[], int len) 
{
    int sum_between=0;
    for(int i=0; i < len; i++) 
    {
        sum_between += abs(arr[i]);
    }
    sum_between -= sum_between_negative(arr, len);
    return sum_between;
}