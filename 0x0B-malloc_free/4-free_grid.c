#include "main.h"
#include <stdlib.h>

/**
 * free_grid - entry point
 * @grid: int
 * @height: int
 */
void free_grid(int **grid, int height)
{
	int cpt;

	for (cpt = 0; i < height; i++)
		free(grid[cpt]);
	free(grid);
}
