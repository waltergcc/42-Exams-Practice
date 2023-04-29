#include <stdio.h>
#include <stdlib.h>

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_count_words(char *s)
{
	int i = 0;
	while (*s)
	{
		if (!ft_is_space(*s))
		{
			i++;
			while (*s && !ft_is_space(*s))
				s++;	
		}
		else
			s++;
	}
	return (i);
}

char	*ft_get_word(char *s)
{
	int i = 0;
	while (s[i] && !ft_is_space(s[i]))
		i++;
	char *word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && !ft_is_space(s[i]))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s)
{
	char **words = (char **)malloc(sizeof(char *) * (ft_count_words(s) + 1));
	if (!words)
		return (NULL);
	int j = 0;
	while (*s)
	{
		if (!ft_is_space(*s))
		{
			words[j] = ft_get_word(s);
			while (*s && !ft_is_space(*s))
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
	char **words = ft_split("I need to test how many new strings ware generated");
	int i = 0;
	while (words[i])
	{
		printf("%s\n", words[i]);
		free(words[i]);
		i++;
	}
	free(words);
} */
