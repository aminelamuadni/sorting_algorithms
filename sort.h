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

#endif /* SORT_H */
