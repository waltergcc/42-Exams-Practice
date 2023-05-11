#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	char *new = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	int i = 0;
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
	char *empty;
	char src[] = "words aand letters";
	empty = ft_strdup(src);
	printf("%s", empty);
	free(empty);
} */
