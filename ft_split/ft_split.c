#include <stdlib.h>
#include <stdio.h>

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

char	**ft_split(char *str)
{
	char size = countWords(str);
	char **words = (char **)malloc(sizeof(char *) * (size + 1));
	if (!words)
		return (NULL);
	int j = 0;
	while (*str)
	{
		if (!isSpace(*str))
		{
			words[j] = getWord(&*str);
			while (!isSpace(*str) && *str)
				str++;
			j++;
		}
		else
			str++;
	}
	words[j] = NULL;
	return (words);
}
/* 
int	main(void)
{
	char s[] = "Words that will be splitted";
	char **words = ft_split(s);
	int	size = countWords(s);
	int i = 0;
	while (i < size)
	{
		printf("%s\n", words[i]);
		free(words[i]);
		i++;
	}
	free(words);
} */