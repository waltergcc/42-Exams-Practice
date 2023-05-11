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

char	*get_word(char *str)
{
	int i = 0;
	while (str[i] && !is_space(str[i]))
		i++;
	char *word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !is_space(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char    **ft_split(char *str)
{
	int j = 0;
	char **words = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!words)
		return (NULL);
	while (*str)
	{
		if (!is_space(*str))
		{
			words[j] = get_word(str);
			while (*str && !is_space(*str))
				str++;
			j++;
		}
		else
			str++;
	}
	words[j] = 0;
	return (words);
}

void	rev_wstr(char *s)
{
	char **words = ft_split(s);
	int end = count_words(s) - 1;
	while (end >= 0)
	{
		ft_putstr(words[end]);
		if (end > 0)
			ft_putstr(" ");
		free(words[end]);
		end--;
	}
	free(words);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		rev_wstr(av[1]);
	}
	write(1, "\n", 1);
}
