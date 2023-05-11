#include <stdio.h>
#include <stdlib.h>

int	absolute_number(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int     *ft_rrange(int start, int end)
{
	int	size = absolute_number(start - end) + 1;
	int	*range = (int *)malloc(sizeof(int) * (size));
	if (!range)
		return (NULL);
	int i = 0;
	while (i < size)
	{
		if (end >= start)
			range[i] = end - i;
		else if (end < start)
			range[i] = end + i; 
		i++;
	}
	return (range);
}
/* 
int	main(void)
{
	int	start[4] = {1, -1, 0, 0};
	int	end[4] = {3, 2, 0, -3};

	for (int i = 0; i < 4; i++)
	{
		int	*range = ft_rrange(start[i], end[i]);
		int	size = absolute_number(start[i] - end[i]) + 1;
		for (int j = 0; j < size; j++)
			printf("%d, ", range[j]);
		printf("\n");
		free(range);
	}
} */