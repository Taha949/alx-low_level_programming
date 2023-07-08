#include "hash_tables.h"



/**
 * key_index - entry point
 *
 * @key: a pointer
 *
 * @size: array
 *
 * Return: an int (the index)
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = 0;

	index = hash_djb2(key);
	index %= size;
	return (index);
}
