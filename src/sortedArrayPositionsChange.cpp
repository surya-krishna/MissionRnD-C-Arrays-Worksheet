/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int incr,first_odd_pos,temp;
	if (Arr == NULL || len < 0)
		return 0;

	for (incr = 0; incr < len;incr++)
	{
		if (Arr[incr]>Arr[incr + 1])
		{
			first_odd_pos = incr;
			break;
		}

	}
	if (Arr[first_odd_pos] > Arr[len-1])
	{
		temp = Arr[first_odd_pos];
		Arr[first_odd_pos] = Arr[len - 1];
		Arr[len - 1] = temp;

	}
	else
	{
		for (incr = incr + 1; incr < len; incr++)
		{
			if (Arr[first_odd_pos] < Arr[incr])
			{
				temp = Arr[first_odd_pos];
				Arr[first_odd_pos] = Arr[incr - 1];
				Arr[incr - 1] = temp;
				break;
			}

		}
	}
	return NULL;
}