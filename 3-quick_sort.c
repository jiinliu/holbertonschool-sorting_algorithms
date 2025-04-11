#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swaps two integers in an array.
 * @array: The array containing the integers.
 * @i: Index of the first element.
 * @j: Index of the second element.
 * @size: Size of the entire array.
 *
 * Description: Swaps the values at the given indices in the array
 * and prints the array after the swap.
 */
static void swap_ints(int *array, int i, int j, size_t size)
{
	int tmp;

	if (i == j || array[i] == array[j])
		return;
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
 * lomuto_partition - Partitions a sub-array using the Lomuto scheme.
 * @array: The array of integers.
 * @low: Starting index of the sub-array.
 * @high: Ending index of the sub-array (pivot index).
 * @size: The size of the entire array.
 *
 * Return: The final index where the pivot is placed.
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(array, i, j, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap_ints(array, i, high, size);
	}
	return (i);
}

/**
 * quick_sort_rec - Recursively sorts sub-arrays using Quick sort.
 * @array: The array of integers.
 * @low: The starting index of the sub-array.
 * @high: The ending index of the sub-array.
 * @size: The size of the entire array.
 */
static void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, pivot_index - 1, size);
		quick_sort_rec(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Implements the Quick sort algorithm using the Lomuto
 * partition scheme. The pivot is always the last element of the sub-array.
 * The array is printed each time two elements are swapped.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_rec(array, 0, size - 1, size);
}
