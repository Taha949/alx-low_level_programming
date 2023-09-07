#include "hash_tables.h"



/**
 * key_index - return the index
 *
 * @key: a pointer
 *
 * @size: array
 *
 * Return: key_index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = 0;

	index = hash_djb2(key);
	index %= size;
	return (index);
}
