#include "sum_between_negative.h"
#include "index_last_negative.h"
#include "index_first_negative.h"
#include <stdio.h>
#include <stdlib.h>

int sum_between_negative(int arr[], int len) 
{
    int sum_negative = 0;
    for (int i = index_first_negative(arr, len); i < index_last_negative(arr, len); i++) 
    {
        sum_negative += abs(arr[i]);
    }
    return sum_negative;
}