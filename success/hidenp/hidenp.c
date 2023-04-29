#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;
	int	match = 0;
	while (s1[i])
	{
		j = i;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				match++;
				break;
			}
			j++;
		}
		i++;
	}
	if (match == i)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		hidenp(av[1], av[2]);
	}
	write(1, "\n", 1);
}
