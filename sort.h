#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int lo, int hi);
void lomuto_quick_sort(int *array, size_t size, int lo, int hi);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
int find_max(int *array, size_t size);
int *initialize_counting_array(int max, int *array, size_t size);
void print_counting_array(int *counting_array, int max);
void counting_sort(int *array, size_t size);
void merge(int *array, int *l, int *r, size_t size);
void merge_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void heapify(int *array, int n, int i, size_t size);
void heap_sort(int *array, size_t size);
int max_value(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int position);
void radix_sort(int *array, size_t size);
void bitonic_swap(int arr[], int a, int b, int dir);
void bitonic_merge(int arr[], int start, int count, int dir);
void bitonic_sort_recursion(int arr[], int start, int count, int dir,
							int total_size);
void bitonic_sort(int *array, size_t size);
void hoare_swap(int *arr, size_t a, size_t b);
size_t hoare_partition(int *arr, ssize_t start, ssize_t end, int len);
void hoare_sort(int *arr, ssize_t start, ssize_t end, int len);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
