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

char	*snake_to_camel(char *camel)
{
	int	i = 0;
	int j = 0;
	int underscores = 0;
	char *snake;

	while (camel[i])
	{
		j = i + 1;
		if (camel[i] == '_')
		{
			underscores++;
			if (camel[j] >= 'a' && camel[j] <= 'z')
				camel[j] -= 32; 
		}
		i++;
	}
	int size = i - underscores;
	snake = (char *)malloc(sizeof(char) * (size + 1));
	if (!snake)
		return (NULL);
	i = 0;
	j = 0;
	while (camel[i])
	{
		if (camel[i] == '_')
			i++;
		snake[j] = camel[i];
		i++;
		j++;
	}
	snake[j] = '\0';
	return (snake);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *snake = snake_to_camel(av[1]);
		ft_putstr(snake);
		free(snake);
	}
	write(1, "\n", 1);
}