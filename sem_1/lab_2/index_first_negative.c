#include "index_first_negative.h"
#include <stdio.h>

int index_first_negative(int arr[], int len)
{
	for (int i; i < len; i++)
    {
		if (arr[i] < 0)
        {
			return i;
        }
    }
    return -1;
}