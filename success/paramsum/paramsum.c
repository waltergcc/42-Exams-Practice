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

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 0;
		while (av[i])
			i++;
		ft_putnbr(i - 1);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
