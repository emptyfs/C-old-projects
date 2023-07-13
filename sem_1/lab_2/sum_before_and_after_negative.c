#include "sum_before_and_after_negative.h"
#include "sum_between_negative.h"
#include <stdio.h>
#include <stdlib.h>

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