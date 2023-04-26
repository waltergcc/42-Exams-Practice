#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_atoi(char *s)
{
	int r = 0;
	int sign = 1;

	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + (*s - '0');
		s++;
	}
	return (sign * r);
}

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

void	add_prime_sum(int n)
{
	int i = 0;
	int sum = 0;
	while (i <= n)
	{
		if (isPrime(i))
			sum += i;
		i++;
	}
	ft_putnbr(sum);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int n = ft_atoi(av[1]);
		if (n >= 0)
			add_prime_sum(n);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}