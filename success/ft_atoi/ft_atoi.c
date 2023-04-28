#include <stdio.h>

int	ft_atoi(const char *str)
{
	int sign = 1;
	int r = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (sign * r);
}
/* 
int	main(void)
{
	printf("%d\n", ft_atoi("-42"));
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("Ceci permet de decouvrir le fonctionnement de ton ft_atoi."));
} */