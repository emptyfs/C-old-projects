#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int comp(const void*, const void*);

int main()
{
    clock_t start;
    int key = 0;
    int arr[1000];

    for(int i = 0; i < 1000; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, 1000, sizeof(int), comp);
    start = clock();

    if(bsearch(&key, arr, 1000, sizeof(int), comp) == NULL)
    {
        printf("doesn't exist\n");
    }

    else
    {
        printf("exists\n");
    }

    printf("%f\n", (start - clock())/CLOCKS_PER_SEC);
    start = clock();

    for(int i = 0; i < 1000; i++)
    {
        if(arr[i] == 0)
        {
            printf("exists\n");
            break;
        }
        printf("doesn't exist\n");
    }
    printf("%f\n", (start - clock())/CLOCKS_PER_SEC);
    return 0;
}

int comp(const void* a, const void* b)
{
    if(*(int*)a > *(int*)b)
    {
        return 1;
    }
    if(*(int*)a < *(int*)b)
    {
        return -1;
    }
    if(*(int*)a == *(int*)b)
    {
        return 0;
    }
}