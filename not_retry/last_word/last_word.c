#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	count_words(char *s)
{
	int i = 0;
	while (*s)
	{
		if (!is_space(*s))
		{
			i++;
			while (*s && !is_space(*s))
				s++;
		}
		else
			s++;
	}
	return (i);
}

void	last_word(char *s)
{
	int last = count_words(s);
	int i = 0;
	while (*s)
	{
		if (!is_space(*s))
		{
			i++;
			while (*s && !is_space(*s))
			{
				if (i == last)
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
		last_word(av[1]);
	}
	write(1, "\n", 1);
}
