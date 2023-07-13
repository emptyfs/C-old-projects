#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "sum_between_negative.h"
#include "sum_before_and_after_negative.h"

int main()
{
    int array[100];
    int N=0;
    int mode;
    char space;
    char checker[4];
    setlocale(LC_ALL, "Russian");

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