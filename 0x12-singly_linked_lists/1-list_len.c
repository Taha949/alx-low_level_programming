#include <stdlib.h>
#include "lists.h"

/**
 * list_len - entry point
 * @h: a pointer
 *
 * Return: an int
 */
size_t list_len(const list_t *h)
{
size_t n;

n = 0;

while (h)
{
n++;
h = h->next;
}
return (n);
}

