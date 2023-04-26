#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	char *new;

	while (src[i])
		i++;	
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/* 
int	main(void)
{
	char s[] = "teste";
	char *empty = ft_strdup(s);
	printf("%s", empty);
	free(empty);
} */