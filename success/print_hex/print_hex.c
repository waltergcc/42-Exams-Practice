#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	print_hex(long n)
{
	char *base = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	ft_putchar(base[n % 16]);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int n = ft_atoi(av[1]);
		if (n >= 0)
			print_hex(n);
	}
	write(1, "\n", 1);
}
