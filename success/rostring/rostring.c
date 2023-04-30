#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, *&s, 1);
		s++;
	}
}

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

char	*get_word(char *s)
{
	int i = 0;
	while (s[i] && !is_space(s[i]))
		i++;
	char *word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && !is_space(s[i]))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s)
{
	char **words = (char **)malloc(sizeof(char *) * (count_words(s) + 1));
	if (!words)
		return (NULL);
	int j = 0;
	while (*s)
	{
		if (!is_space(*s))
		{
			words[j] = get_word(s);
			while (*s && !is_space(*s))
				s++;
			j++;
		}
		else
			s++;
	}
	words[j] = 0;
	return (words);
}

void	rostring(char *s)
{
	char **words = ft_split(s);
	char *last = words[0];
	int end = count_words(s);
	int i = 1;

	while (i < end)
	{
		ft_putstr(words[i]);
		ft_putstr(" ");
		free(words[i]);
		i++;
	}
	ft_putstr(last);
	free(last);
	free(words);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		rostring(av[1]);
	}
	write(1, "\n", 1);
}
