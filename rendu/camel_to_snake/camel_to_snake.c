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
	int i = 0;
	int j = 0;
	while (camel[i])
	{
		if (camel[i] >= 'A' && camel[i] <= 'Z')
			j++;
		i++;
	}
	char	*snake = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!snake)
		return (NULL);
	i = 0;
	j = 0;
	while (camel[i])
	{
		if (camel[i] >= 'A' && camel[i] <= 'Z')
		{
			camel[i] += 32;
			snake[j] = '_';
			j++;

		}
		snake[j] = camel[i];
		j++;
		i++;
	}
	snake[j] = '\0';
	return (snake);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*snake = camel_to_snake(av[1]);
		ft_putstr(snake);
		free(snake);
	}
	write(1, "\n", 1);
}