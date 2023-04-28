#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	int i = ft_strlen(src);
	char *s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (src[i])
	{
		s[i] = src[i];
		i++; 
	}
	s[i] = '\0';
	return (s);
}
/* 
int	main(void)
{
	char src[] = "to be duplicated";
	char *empty = ft_strdup(src);
	printf("%s\n", empty);
	free(empty);
} */