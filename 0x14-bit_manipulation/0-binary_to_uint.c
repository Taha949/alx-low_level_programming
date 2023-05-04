#include "main.h"
#include <stdlib.h>

/**
 * binary_to_uint - entry point
 * @b: string
 *
 * Return: int
 */

unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;
    int len = 0;

    if (b == NULL)
        return 0;

    while (b[len] != '\0')
        len++;
    for (int i = 0; i < len; i++)
    {
        if (b[i] == '1')
            result += (1u << (len - i - 1));
        else if (b[i] != '0')
            return 0;
    }

    return result;
}

