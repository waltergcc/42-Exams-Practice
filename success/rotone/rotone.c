#include <unistd.h>

void	rotone(char *s)
{
	while (*s)
	{
		if ((*s >= 'a' && *s <= 'y') || (*s >= 'A' && *s <= 'Y'))
			*s += 1;
		else if (*s == 'z' || *s == 'Z')
			*s -= 25;
		write(1, *&s, 1);
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		rotone(av[1]);
	}
	write(1, "\n", 1);
}
