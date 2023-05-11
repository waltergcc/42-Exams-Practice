#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	rev_print(char *s)
{
	int i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		write(1, &s[i], 1);
		i--;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		rev_print(av[1]);
	}
	write(1, "\n", 1);
}
