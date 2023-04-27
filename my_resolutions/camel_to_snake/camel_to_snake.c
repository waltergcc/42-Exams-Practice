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

char	*camel_to_snake(char *camel)
{
	int	i = 0;
	int j = 0;
	int upper = 0;
	char *snake;

	while (camel[i])
	{
		if (camel[i] >= 'A' && camel[i] <= 'Z')
			upper++;
		i++;
	}
	int size = i + upper;
	snake = (char *)malloc(sizeof(char) * (size + 1));
	if (!snake)
		return (NULL);
	i = 0;
	j = 0;
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
		char *snake = camel_to_snake(av[1]);
		ft_putstr(snake);
		free(snake);
	}
	write(1, "\n", 1);
}