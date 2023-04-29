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

void	camel_to_snake(char *camel)
{
	char *snake;
	int	sep = 0;
	int	i = 0;

	while (camel[i])
	{
		if (camel[i] >= 'A' && camel[i] <= 'Z')
			sep++;
		i++;
	}
	snake = (char *)malloc(sizeof(char) * ((i + sep) + 1));
	i = 0;
	int j = 0;
	while (camel[i])
	{
		if (camel[i] >= 'A' && camel[i] <= 'Z')
		{
			snake[j] = '_';
			j++;
			snake[j] = camel[i] + 32;
		}
		else
			snake[j] = camel[i];
		j++;
		i++;
	}
	snake[j] = '\0';
	ft_putstr(snake);
	free(snake);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		camel_to_snake(av[1]);
	}
	write(1, "\n", 1);
}
