#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

int	isSpace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	countWords(char *s)
{
	int	count = 0;
	while (*s)
	{
		if (!isSpace(*s))
		{
			count++;
			while (!isSpace(*s) && *s)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	*getWord(char *s)
{
	int i = 0;
	char *word;
	while (!isSpace(s[i]) && s[i])
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (!isSpace(s[i]) && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s)
{
	char size = countWords(s);
	char **words = (char **)malloc(sizeof(char *) * (size + 1));
	if (!words)
		return (NULL);
	int j = 0;
	while (*s)
	{
		if (!isSpace(*s))
		{
			words[j] = getWord(&*s);
			while (!isSpace(*s) && *s)
				s++;
			j++;
		}
		else
			s++;
	}
	words[j] = NULL;
	return (words);
}

void	rostring(char *s)
{
	char **words = ft_split(s);
	char *last = words[0];
	int	j = countWords(s);
	int i = 1;
	while (i < j)
	{
		ft_putstr(words[i]);
		if (i != j)
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