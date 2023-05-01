#include "lists.h"

/**
 * print_listint - entry point
 * @h: linked
 * Return: nodes
 */
size_t print_listint(const listint_t *h)
{
	if (h == NULL) {
		return (0);
	}

	size_t num = 1;
	printf("%d\n", h->n);

	num += print_listint(h->next);

	return (num);
}

