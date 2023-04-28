#include <unistd.h>

void	ulstr(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		else if (*s >= 'A' && *s <= 'Z')
			*s += 32;
		write(1, &*s, 1); 
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ulstr(av[1]);
	}
	write(1, "\n", 1);
}