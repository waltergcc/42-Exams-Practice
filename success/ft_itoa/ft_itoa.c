#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_digit_places(long n)
{
	int i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
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
	long	n = nbr;
	char	*s;

	int i = ft_digit_places(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
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
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	return (s);

}
/* 
int	main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
} */
