#include <stdio.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}
/* 
int	main(void)
{
	printf("%d\n", ft_strlen("1234567890"));
} */