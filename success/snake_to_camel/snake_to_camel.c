#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	snake_to_camel(char *snake)
{
	char *camel;
	int	sep = 0;
	int	i = 0;

	while (snake[i])
	{
		if (snake[i] == '_')
		{
			if (snake[i + 1] >= 'a' && snake[i + 1] <= 'z')
				snake[i + 1] -= 32; 
			sep++;
		}
		i++;
	}
	camel = (char *)malloc(sizeof(char) * ((i - sep) + 1));
	i = 0;
	int j = 0;
	while (snake[i])
	{
		if (snake[i] == '_')
		{
			i++;
			camel[j] = snake[i];
		}
		else
			camel[j] = snake[i];
		j++;
		i++;
	}
	camel[j] = '\0';
	ft_putstr(camel);
	free(camel);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		snake_to_camel(av[1]);
	}
	write(1, "\n", 1);
}
