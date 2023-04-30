#include <stdio.h>

int	ft_atoi(const char *str)
{
	int r = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
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
	printf("%d\n", ft_atoi("-224567"));
} */