#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	first_word(char *s)
{
	while (*s)
	{
		if (!is_space(*s))
		{
			while (*s && !is_space(*s))
			{
				write(1, &*s, 1);
				s++;
			}
			return;
		}
		else
			s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		first_word(av[1]);
	}
	write(1, "\n", 1);
}
