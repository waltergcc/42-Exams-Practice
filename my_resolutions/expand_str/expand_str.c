#include <unistd.h>

int	isSpace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	countWords(char *s)
{
	int	count = 0;
	while (*s)
	{
		if (!isSpace(*s))
		{
			count++;
			while (!isSpace(*s) && *s)
				s++;
		}
		else
			s++;
	}
	return (count);
}

void	expand_str(char *s)
{
	int	count = 0;
	int	size = countWords(s);
	while (*s)
	{
		if (!isSpace(*s))
		{
			count++;
			while (!isSpace(*s) && *s)
			{
				write(1, &*s, 1);
				s++;
			}
			if (count != size)
				write(1, "   ", 3);
		}
		else
			s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		expand_str(av[1]);
	}
	write(1, "\n", 1);
}