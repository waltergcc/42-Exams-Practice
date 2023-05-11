#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int	max = tab[0];
	int i = 0;
	while (i < (int) len)
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
	int	tab[5] = {1254789, 5, 0, 564, 12365};

	int n = max(tab, 5);
	printf("%d\n", n);
} */