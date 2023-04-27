#include <unistd.h>

void	rot_13(char *s)
{
	while (*s)
	{
		if ((*s >= 'a' && *s <= 'm') || (*s >= 'A' && *s <= 'M'))
			*s += 13;
		else if ((*s >= 'n' && *s <= 'z') || (*s >= 'N' && *s <= 'Z'))
			*s -= 13;
		write(1, &*s, 1);
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		rot_13(av[1]);
	}
	write(1, "\n", 1);
}