#include <unistd.h>

void	rstr_capitalizer(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		i++;
	}
	i = 0;
	int j = 0;
	while (s[i])
	{
		j = i + 1;
		if (s[j] == ' ' || s[j] == '\t' || s[j] == '\0')
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			rstr_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
