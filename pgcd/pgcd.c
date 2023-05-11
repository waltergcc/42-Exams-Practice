#include <stdio.h>
#include <stdlib.h>

int	pgcd(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (pgcd(b, a % b));
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int a = atoi(av[1]);
		int b = atoi(av[2]);
		if (a >= 0 && b >= 0)
			printf("%d", pgcd(a, b));
	}
	printf("\n");
}
