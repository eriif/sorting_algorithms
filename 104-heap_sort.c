#include "sort.h"
#include <stdio.h>
/**
 * swap - utility function to swap to integers
 * @a: int a
 * @b: int b
 */
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}
/**
 * maxHeapify - the main funtion to heapify a max heap
 * @array: array
 * @size: size of the array for print
 * @idx: index
 * @n: size of the array to run
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < (int)n && array[right] > array[largest])
		largest = right;
	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}
/**
 * heap_sort - the main fuction to sort an array of given size
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == '\0' || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeapify(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		maxHeapify(array, size, 0, i);
	}
}
