#include <stdio.h>
#include <stdlib.h>

int	isPrime(int n)
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

void	fprime(int n)
{
	if (n == 1)
		printf("1");
	int i = 2;
	int first = 1;
	while (i <= n)
	{
		if (n % i == 0 && isPrime(i))
		{
			if (first)
			{
				printf("%d", i);
				first = 0;
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
		int n = atoi(av[1]);
		if (n >= 0)
			fprime(n);
	}
	printf("\n");
}