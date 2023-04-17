#include "dog.h"

/**
 * init_dog - Entry point
 *
 * Description: entry point
 * @d: pointer
 * @name: name string
 * @age: af loat
 * @owner: name string
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == 0)
		return;
	d->name = name;
	d->age = age;
	d->owner = owner;
}
