#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
{
   int           x;
   int           y;
}               t_point;

void  fill(char **tab, t_point size, t_point begin, char to_fill, char c)
{
	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
		return ;
	if (tab[begin.y][begin.x] != to_fill)
		return ;
		
	tab[begin.y][begin.x] = c;

	fill(tab, size, (t_point){begin.x, begin.y - 1}, to_fill, c);
	fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill, c);
	fill(tab, size, (t_point){begin.x - 1, begin.y}, to_fill, c);
	fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill, c);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char to_fill = tab[begin.y][begin.x];
	char c = 'F';

	fill(tab, size, begin, to_fill, c);
}
/* 
char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		".1111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {0, 0};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
} */