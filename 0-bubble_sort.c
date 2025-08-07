#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sorts array of integers in ascending order using Bubble sort
 * @array: the array of int to be sorted
 * @size: how many elements in array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t total_pass = 0, actual_pass;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (total_pass < size - 1)
		{
		actual_pass = 0;
			while (actual_pass < size - total_pass - 1)
			{
				if (array[actual_pass] > array[actual_pass + 1])
				{
					temp = array[actual_pass];
					array[actual_pass] = array[actual_pass + 1];
					array[actual_pass + 1] = temp;
					print_array(array, size);
				}
				actual_pass++;
			}
		}
}


