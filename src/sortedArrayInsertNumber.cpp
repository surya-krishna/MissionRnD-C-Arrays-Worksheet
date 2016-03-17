/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>


int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int shift,middle_pos, previous = num, temp, required_pos, position, initial_pos = 0, final_pos = len;

	if (Arr == NULL || len<0)
	{
		return NULL;
	}


	while(initial_pos <= final_pos)
	{
		middle_pos = (initial_pos + final_pos) / 2;
		if (middle_pos == 0 || middle_pos == len)
		{
			required_pos = middle_pos;
			break;
		}
		else
		if ((Arr[middle_pos] < num && Arr[(middle_pos) + 1] > num))
		{
			required_pos = middle_pos + 1;
			break;
		}
		else
		if ((Arr[(middle_pos) - 1] < num && Arr[middle_pos] > num))
		{
			required_pos = middle_pos;
			break;
		}
		else
		if (Arr[middle_pos] > num)
		{
			final_pos = middle_pos-1;
		}
		else
		if (Arr[final_pos / 2] < num)
		{
			initial_pos = middle_pos + 1;
		}
		else
		if (Arr[middle_pos] == num)
		{
			required_pos = middle_pos + 1;
			break;
		}
	}

	Arr = (int *)realloc(Arr, sizeof(int)*(len + 1));

	for (shift = required_pos; shift < len + 1; shift++)
	{
		temp = Arr[shift];
		Arr[shift] = previous;
		previous = temp;
	}

	return Arr;
}