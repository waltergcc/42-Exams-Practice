#include <unistd.h>

int	isSpace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

void	first_word(char *s)
{
	int count = 0;
	while (*s)
	{
		if (!isSpace(*s))
		{
			count++;
			while (!isSpace(*s) && *s)
			{
				if (count == 1)
					write(1, &*s, 1);
				s++;
			}
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