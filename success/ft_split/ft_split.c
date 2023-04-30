#include <stdio.h>
#include <stdlib.h>

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
/* 
int	main(void)
{
	char s[] = "words to be splitted";
	char **words = ft_split(s);
	int end = count_words(s);
	int i = 0;

	while (i < end)
	{
		printf("%s\n", words[i]);
		free(words[i]);
		i++;
	}
	free(words);
} */
