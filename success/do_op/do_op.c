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

void	do_op(long a, long b, char op)
{
	if (op == '+')
		ft_putnbr(a + b);
	else if (op == '-')
		ft_putnbr(a - b);
	else if (op == '*')
		ft_putnbr(a * b);
	else if (op == '/')
		ft_putnbr(a / b);
	else if (op == '%')
		ft_putnbr(a % b);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		long a = ft_atoi(av[1]);
		long b = ft_atoi(av[3]);
		char op = av[2][0];
		do_op(a, b, op);
	}
	write(1, "\n", 1);
}
