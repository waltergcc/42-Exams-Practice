#include <unistd.h>

char	get_mirror(char c)
{
	if (c >= 'a' && c <= 'z')
		return ('a' + 'z' - c);
	else if (c >= 'A' && c <= 'Z')
		return ('A' + 'Z' - c);
	return (0);	
}

void	alpha_mirror(char *s)
{
	while (*s)
	{
		if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
			*s = get_mirror(*s);
		write(1, *&s, 1);
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
