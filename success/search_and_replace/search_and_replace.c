#include <unistd.h>

void	search_and_replace(char *s, char search, char replace)
{
	while (*s)
	{
		if (*s == search)
			write(1, &replace, 1);
		else
			write(1, &*s, 1);
		s++;
	}

}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (!av[2][1] && !av[3][1])
		search_and_replace(av[1], av[2][0], av[3][0]);
	}
	write(1, "\n", 1);
}
