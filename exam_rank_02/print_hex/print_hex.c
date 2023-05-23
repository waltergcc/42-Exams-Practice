#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int r = 0;
	int sg = 1;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (sg * r);
}

void	print_hex(int n)
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