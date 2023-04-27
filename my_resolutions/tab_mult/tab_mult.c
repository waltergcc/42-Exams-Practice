#include <unistd.h>

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

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

void	tab_mult(long n)
{
	int check = 0;

	if (n * 9 <= 2147483647)
		check = 1;
	else
		check = -1;
	int i = 1;
	int r = 0;
	if (n >= 0 && check > 0)
	{
		while (i <= 9)
		{
			r = i * n;
			ft_putnbr(i);
			ft_putstr(" x ");
			ft_putnbr(n);
			ft_putstr(" = ");
			ft_putnbr(r);
			ft_putchar('\n');
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int n = ft_atoi(av[1]);
		tab_mult(n);
	}
	else
		write(1, "\n", 1);
}