#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <stdbool.h>

char** input(int*, int*); // считывание текста
void hatred_seven(char**, int*); // перезапись предложений

int main()
{   
    int transfer;
    int senten = 5;
    char** arr;
    int size = 5;
    arr = input(&size, &senten);
    transfer = senten;
    hatred_seven(arr, &senten);

    for(int i = 0; i<senten; i++)
    {
        printf("%s\n", arr[i]);
    }

    printf("Количество предложений до %d и количество предложений после %d", transfer-1, senten-1);

    for(int i = 0; i<size; i++)
    {
        free(arr[i]);
    }

    free(arr);
    return 0;
}

char** input(int* size, int* senten)
{
    char letter_dragon;
    char letter;
    int index = 0; // индекс текущего символа в предложении
    int count = 0; // индекс текущего предложения 
    int k = 0; // счетчик подряд идущих символов, формирующих "Dragon flew away!"
    bool check = true; // условие выполнения считывания 
    char* end = "Dragon flew away!";
    char** arr = (char**)calloc((*size), sizeof(char*)); // указатель на массив предложений

    for(int i = 0; i < 5; i++)
    {
        arr[i] = (char*)calloc(30, sizeof(char));
    }

    while(check)
    {
        letter = getchar();
        if(letter == '\n')
        {
            continue;
        }

        if((index == 0) && (letter == 'D'))
        {
            if((count % 5 == 0) && (count != 0))
            {
                arr = (char**)realloc(arr, (count+5) * sizeof(char*));
                *size += 5;
                for(int i = count; i < count+5; i++)
                {
                    arr[i] = (char*)calloc(30, sizeof(char));
                }
            }

            k = 0;
            arr[count][index] = letter;
            index++;
            k++;

            for(int i = 1; i < 17; i++)
            {
                letter_dragon = getchar();
                arr[count][index] = letter_dragon;
                index++;
                if(letter_dragon == end[i])
                {
                    k++;
                }

                else
                {
                    k = 0;
                    break;
                }
            }

            if(k == 17)
            {
                check = false;
                arr[count][index+1] == '\0';
            }
            continue;
        }

        if((index == 0) && (letter != 'D'))
        {
            if((count % 5 == 0) && (count != 0))
            {
                arr = (char**)realloc(arr, (count+5) * sizeof(char*));
                *size += 5;
                for(int i = count; i < count+5; i++)
                {
                    arr[i] = (char*)calloc(30, sizeof(char));
                }
            }
            arr[count][index] = letter;
            index++;
            continue;
        }

        if((index != 0) && (letter != ';') && (letter != '?') && (letter != '.'))
        {
            if(index % 30 == 0)
            {
                arr[count] = (char*)realloc(arr[count], (index+30) * sizeof(char));
            }
            arr[count][index] = letter;
            index++;
            continue;
        }
        
        if((index != 0) && ((letter == ';') || (letter == '?') || (letter == '.')))
        {
            if(index % 30 == 0)
            {
                arr[count] = (char*)realloc(arr[count], (index+2) * sizeof(char));
            }

            arr[count][index] = letter;
            arr[count][index+1] = '\0';
            getchar();
            index = 0;
            count++;
            continue;
        }
    }
    *senten = count+1;
    return arr;
}

void hatred_seven(char** arr, int* senten)
{
    int index = 0;
    int count = 0;

    while(1)
    {
        if(arr[count][index] == '\0')
        {
            count++;
            index = 0;
            if(count == (*senten)){
                break;
            }
            else{
                continue;
            }
        }
        if(arr[count][index] != '7')
        {
            index++;
            continue;
        }
        if(arr[count][index] == '7')
        {
            for(int i = count; i < (*senten) - 1; i++)
            {
                if(strlen(arr[i]) < strlen(arr[i+1]))
                {
                    arr[i] = (char*)realloc(arr[i], (strlen(arr[i+1])+1) * sizeof(char));
                }
                strcpy(arr[i], arr[i+1]);
            }
            *senten = *senten - 1;
            index = 0;
        }
    }
}