#include <unistd.h>
#include <stdlib.h>

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

void	do_op(int a, int b, char op)
{
	if (op == '-')
		ft_putnbr(a - b);
	else if (op == '+')
		ft_putnbr(a + b);
	else if (op == '/')
		ft_putnbr(a / b);
	else if (op == '*')
		ft_putnbr(a * b);
	else if (op == '%')
		ft_putnbr(a % b);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int a = atoi(av[1]);
		int b = atoi(av[3]);
		char op = av[2][0];
		do_op(a, b, op);
	}
	ft_putchar('\n');
}