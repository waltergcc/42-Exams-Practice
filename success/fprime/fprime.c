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
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_is_prime(int n)
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

int	ft_atoi(char *s)
{
	int r = 0;
	int	sg = 1;

	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sg = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + (*s - '0');
		s++;
	}
	return (r * sg);
}

void	fprime(int n)
{
	if (n == 1)
		ft_putchar('1');
	int i = 2;
	int fst = 1;
	while (i <= n)
	{
		if (n % i == 0 && ft_is_prime(i))
		{
			if (fst)
			{
				ft_putnbr(i);
				fst = 0;
			}
			else
			{
				ft_putchar('*');
				ft_putnbr(i);
			}
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
		int n = ft_atoi(av[1]);
		if (n >= 0)
			fprime(n);
	}
	write(1, "\n", 1);
}
