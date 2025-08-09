#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include "sort.h"

/**
 * swap_two_values - swaps two integers in place
 * @first_no: pointer to first int
 * @second_no: pointer to second int
 *
 * Return: void
 */
void swap_two_values(int *first_no, int *second_no)
{
	int temp = *first_no;
	*first_no = *second_no;
	*second_no = temp;
}

/**
 * partition_arr - uses Lomuto partitioning to rearrange numbers
 * @array: the array of int to be sorted
 * @size: how many elements in array
 * @start_pos: position to start
 * @end_pos: end position
 *
 * Return: int of where pivot is
 */
int partition_arr(int *array, size_t size, ssize_t start_pos, ssize_t end_pos)
{
	int pivot_value = array[end_pos];
	ssize_t pos_for_smaller = start_pos - 1;
	ssize_t current_pos = start_pos;

	while (current_pos < end_pos)
	{
		if (array[current_pos] < pivot_value)
		{
			pos_for_smaller++;

			if (pos_for_smaller != current_pos)
			{
				swap_two_values(&array[pos_for_smaller], &array[current_pos]);
				print_array(array, size);
			}
		}
		current_pos++;
	}
	if ((pos_for_smaller + 1) != end_pos)
	{
		swap_two_values(&array[pos_for_smaller + 1], &array[end_pos]);
		print_array(array, size);
	}

	return (pos_for_smaller + 1);
}

/**
 * help_sort - recursive quick sort to help sort
 * @array: the array of int to be sorted
 * @size: how many elements in array
 * @start_pos: position to start
 * @end_pos: end position
 *
 * Return: int of where pivot is
 */
void help_sort(int *array, size_t size, ssize_t start_pos, ssize_t end_pos)
{
	if (start_pos < end_pos)
	{
		int pivot_final_pos = partition_arr(array, size, start_pos, end_pos);

		help_sort(array, size, start_pos, pivot_final_pos - 1);

		help_sort(array, size, pivot_final_pos + 1, end_pos);
	}
}

/**
 * quick_sort - sorts array of int in asc order with quick
 * @array: the array of int to be sorted
 * @size: how many elements in array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	help_sort(array, size, 0, size - 1);
}
