#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	decimal_places(long n)
{
	int i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long n = nbr;
	int i = decimal_places(n);
	char *s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i--] = '\0';
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
	while (n)
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
	char *empty = ft_itoa(INT_MAX);
	printf("%s\n", empty);
	free(empty);

	empty = ft_itoa(INT_MIN);
	printf("%s\n", empty);
	free(empty);

	empty = ft_itoa(0);
	printf("%s\n", empty);
	free(empty);

	empty = ft_itoa(-42);
	printf("%s\n", empty);
	free(empty);

	empty = ft_itoa(42);
	printf("%s\n", empty);
	free(empty);
} */
