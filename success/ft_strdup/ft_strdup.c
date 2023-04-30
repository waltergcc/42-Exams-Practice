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
	char *dup = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	int i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/* 
int	main(void)
{
	char *empty;
	char	s[] = "words and letters plus anything else";
	empty = ft_strdup(s);
	printf("%s\n", empty);
	free(empty);
} */
