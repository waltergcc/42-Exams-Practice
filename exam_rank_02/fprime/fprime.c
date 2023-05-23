#include <stdio.h>
#include <stdlib.h>

int	is_prime(long n)
{
	if (n < 2)
		return (0);
	int i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	fprime(long n)
{
	if (n == 1)
		printf("1");
	int i = 2;
	int fst = 1;
	while (i <= n)
	{
		if (n % i == 0 && is_prime(i))
		{
			if (fst)
			{
				fst = 0;
				printf("%d", i);
			}
			else
				printf("*%d", i);
			n /= i;
		}
		else
			i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		long n = atoi(av[1]);
		if (n >= 0)
			fprime(n);
	}
	printf("\n");
}
