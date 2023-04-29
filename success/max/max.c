#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int max = 0;
	unsigned int i = 0;
	if (!tab || !len)
		return (0);
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
	int tab[6] = {-1, 2, 36, 99, -7, 100};
	int len = 6;

	printf("%d\n", max(tab, len));
} */
