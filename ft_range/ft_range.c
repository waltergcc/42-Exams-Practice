#include <stdio.h>
#include <stdlib.h>

int	absoluteNumber(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int     *ft_range(int start, int end)
{
	int size = absoluteNumber(start - end) + 1;
	int *range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (NULL);

	int i = 0;
	if (start <= end)
	{
		while (i < size)
		{
			range[i] = start + i;
			i++;
		}
	}
	else if (start > end)
	{
		while (i < size)
		{
			range[i] = start - i;
			i++;
		}
	}
	return (range);
}
/* 
int	main(void)
{
	int	start[5] = {1, -1, 0, 0, 3};
	int	end[5] = {3, 2, 0, -3, 8};

	for (int i = 0; i < 5; i++)
	{
		int *range = ft_range(start[i], end[i]);
		int size = absoluteNumber(start[i] - end[i]) + 1;
		for (int j = 0; j < size; j++)
			printf("%d, ", range[j]);
		free(range);
		printf("\n");
	}
} */