#include <unistd.h>

int	ft_get_index(char c)
{
	int i = 0;
	if (c >= 'a' && c <= 'z')
		i = c - 'a';
	else if (c >= 'A' && c <= 'Z')
		i = c - 'A';
	return (i);
}

void	repeat_alpha(char *s)
{
	int i = 0;
	while (*s)
	{
		if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
		{
			i = ft_get_index(*s) + 1;
			while (i--)
				write(1, &*s, 1);
		}
		else
			write(1, &*s, 1);
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		repeat_alpha(av[1]);
	}
	write(1, "\n", 1);
}
