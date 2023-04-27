#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	if (!tab || !len)
		return (0);
	unsigned int i = 0;
	int max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
/* 
int	main(void)
{
	int tab[5] = {0, 7890, -32, 1898, 3};
	printf("%d", max(tab, 5));
} */