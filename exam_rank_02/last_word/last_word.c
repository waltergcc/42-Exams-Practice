#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	count_words(char *s)
{
	int count = 0;
	while (*s)
	{
		if (!is_space(*s))
		{
			count++;
			while (*s && !is_space(*s))
				s++;
		}
		else
			s++;
	}
	return (count);
}

int	last_word(char *s)
{
	int count = 0;
	int	last = count_words(s);
	while (*s)
	{
		if (!is_space(*s))
		{
			count++;
			while (*s && !is_space(*s))
			{
				if (count == last)
					write(1, &*s, 1);
				s++;
			}
		}
		else
			s++;
	}
	return (count);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		last_word(av[1]);
	}
	write(1, "\n", 1);
}
