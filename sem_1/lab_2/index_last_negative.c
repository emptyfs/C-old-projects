#include "index_last_negative.h"
#include <stdio.h>

int index_last_negative(int arr[], int len)
{
	for (int i = len - 1; i >= 0; i--)
    {
        if (arr[i] < 0)
        {
           	return i;
        }
    }
	return -1;
}