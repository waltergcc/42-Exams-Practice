#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

char	*snake_to_camel(char *snake)
{
	int	j = 0;
	int	i = 0;

	while (snake[i])
	{
		if (snake[i] == '_')
		{
			if (snake[i + 1] >= 'a' && snake[i + 1] <= 'z')
				snake[i + 1] -= 32;
			j++;
		}
		i++;
	}
	char *camel = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!camel)
		return (NULL);
	i = 0;
	j = 0;
	while (snake[i])
	{
		if (snake[i] == '_')
			i++;
		camel[j] = snake[i];
		i++;
		j++;
	}
	camel[j] = '\0';
	return(camel);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *camel = snake_to_camel(av[1]);
		ft_putstr(camel);
		free(camel);
	}
	write(1, "\n", 1);
}
