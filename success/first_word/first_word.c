#include <unistd.h>


int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	first_word(char *s)
{
	int i = 0;
	while (*s)
	{
		if (!ft_is_space(*s))
		{
			i++;
			while (*s && !ft_is_space(*s))
			{
				if (i == 1)
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