#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts array of int in asc order with selection
 * @array: the array of int to be sorted
 * @size: how many elements in array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t current_pos = 0, pos_being_checked, smallest_value;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (current_pos < size - 1)
	{
		smallest_value = pos_being_checked;
		pos_being_checked = current_pos + 1;

		while (pos_being checked < size)
		{
			if (array[pos_being_checked] < array[smallest_value])
			smallest_value = pos_being_checked;
		pos_being_checked++;
	}

	if (smallest_value != current_pos)
	{
		temp = array[current_pos];
		array[current_pos] = array[smallest_value];
		array[smallest_value] = temp;

		print_array(array, size);
	}
	current_pos++;
}
