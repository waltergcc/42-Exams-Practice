#include <unistd.h>
#include <limits.h>

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
	int sg = 1;

	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '-' || *s == '+')
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
	return (sg * r);
}

void	print_hex(long n)
{
	char *base = "0123456789abcdef";

	if (n > 16)
		print_hex(n / 16);
	ft_putchar(base[n % 16]);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		long n = ft_atoi(av[1]);
		if (n >= 0)
			print_hex(n);
	}
	write(1, "\n", 1);
}
