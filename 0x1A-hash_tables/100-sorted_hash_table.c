#include "hash_tables.h"
/**
 * shash_table_create - entry point
 *
 * @size: an int
 * Return: a pointerr
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sh_table;
	unsigned long int i;

	sh_table = malloc(sizeof(shash_table_t));
	if (!sh_table)
		return (NULL);
	sh_table->size = size;
	sh_table->shead = NULL;
	sh_table->stail = NULL;
	sh_table->array = malloc(sizeof(shash_node_t) * size);
	if (!sh_table->array)
	{
		free(sh_table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		sh_table->array[i] = NULL;
	}
	return (sh_table);
}

/**
 * make_shash_node - entry point
 * @key: pointerr
 * @value: pointerr
 *
 * Return: pointer or null
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *sh_node;

	sh_node = malloc(sizeof(shash_node_t));
	if (!sh_node)
		return (NULL);
	sh_node->key = strdup(key);
	if (!sh_node->key)
	{
		free(sh_node);
		return (NULL);
	}
	sh_node->value = strdup(value);
	if (!sh_node->value)
	{
		free(sh_node->key);
		free(sh_node);
		return (NULL);
	}
	sh_node->next = sh_node->snext = sh_node->sprev = NULL;
	return (sh_node);
}

/**
 * add_to_sorted_list - entry point
 * @table: pointerr
 * @node: pointerr
 *
 * Return: Void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *temp_var;

	if (!table->shead && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	temp_var = table->shead;
	while (temp_var != NULL)
	{
		if (strcmp(node->key, temp_var->key) < 0)
		{
			node->snext = temp_var;
			node->sprev = temp_var->sprev;
			temp_var->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		temp_var = temp_var->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set -  entry point
 * @ht: pointerr
 * @key: pointerr
 * @value: pointerr
 * Return: 0 or 1
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new_value;
	shash_node_t *sh_node, *temp_var;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
		key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	temp_var = ht->array[index];
	while (temp_var != NULL)
	{
		if (strcmp(temp_var->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(temp_var->value);
			temp_var->value = new_value;
			return (1);
		}
		temp_var = temp_var->next;
	}
	sh_node = make_shash_node(key, value);
	if (sh_node == NULL)
		return (0);
	sh_node->next = ht->array[index];
	ht->array[index] = sh_node;
	add_to_sorted_list(ht, sh_node);
	return (1);
}

/**
 * shash_table_get - entry point
 * @ht: pointerr
 * @key: pointerr
 *
 * Return: value or null
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *temp_var;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
		key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	temp_var = ht->array[index];
	while (temp_var != NULL)
	{
		if (strcmp(temp_var->key, key) == 0)
			return (temp_var->value);
		temp_var = temp_var->next;
	}
	return (NULL);
}

/**
 * shash_table_print - rntry point
 * @ht: pointerr
 *
 * Return: Void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp_var;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	temp_var = ht->shead;
	while (temp_var != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", temp_var->key, temp_var->value);
		flag = 1;
		temp_var = temp_var->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - entry point
 * @ht: pointerr
 *
 * Return: Void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp_var;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	temp_var = ht->stail;
	while (temp_var != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", temp_var->key, temp_var->value);
		flag = 1;
		temp_var = temp_var->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - entry point
 * @ht: pointerr
 *
 * Return: Void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i] != NULL)
		{
			next = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
