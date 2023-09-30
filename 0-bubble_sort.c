#include "sort.h"

/**
 * swap_it - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_it(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t num, len = size;
	bool check = false;

	if (array == NULL || size < 2)
		return;

	while (check == false)
	{
		check = true;
		for (num = 0; num < len - 1; num++)
		{
			if (array[num] > array[num + 1])
			{
				swap_it(array + num, array + num + 1);
				print_array(array, size);
				check = false;
			}
		}
		len--;
	}
}
