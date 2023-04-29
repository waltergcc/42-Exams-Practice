#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	gcd(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (gcd(b, a % b));
}

void	pgcd(int a, int b)
{
	int r = gcd(a, b);
	printf("%d", r);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int a = atoi(av[1]);
		int b = atoi(av[2]);
		if (a >= 0 && b >= 0)
			pgcd(a, b);
	}
	printf("\n");
}
