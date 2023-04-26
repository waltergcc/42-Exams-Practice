#include <stdio.h>
#include <stdlib.h>

int	digitPlaces(long n)
{
	int i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long n = nbr;
	int i = digitPlaces(n);
	char *s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	i--;
	if (n == 0)
	{
		s[0] = '0'; 
		return (s);
	}
	if (n < 0)
	{
		s[0] = '-'; 
		n = -n;
	}
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (s);
}
/* 
int	main(void)
{
	char *empty = ft_itoa(2147483647);
	printf("%s", empty);
	free(empty);
} */
