#include <unistd.h>

int	get_index(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c -'a' + 1);
	else if (c >= 'A' && c <= 'Z')
		return (c -'A' + 1);
	return (0);
}

void	repeat_alpha(char *s)
{
	int loop = 0;
	while (*s)
	{
		if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
		{
			loop = get_index(*s);
			while (loop--)
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
