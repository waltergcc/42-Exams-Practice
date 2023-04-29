#include <unistd.h>

void	alpha_mirror(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s = 'a' + 'z' - *s;
		if (*s >= 'A' && *s <= 'Z')
			*s = 'A' + 'Z' - *s;
		write(1, &*s, 1);
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		alpha_mirror(av[1]);
	}
	write(1, "\n", 1);
}
