#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	if (str_base < 2 || str_base > 16)
		return (0);
	int r = 0;
	int sg = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sg = -1;
		str++;
	}

	while (*str)
	{
		int d = 0;
		if (*str >= '0' && *str <= '9')
			d = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			d = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			d = *str - 'A' + 10;
		else
			break;
		if (d >= str_base)
			break;
		r = r * str_base + d;
		str++;
	}
	return (sg * r);
}
/* 
int	main(void)
{
	printf("%d\n", ft_atoi_base("a", 16));
	printf("%d\n", ft_atoi_base("fF", 16));
	printf("%d\n", ft_atoi_base("12fdb3", 16));
	printf("%d\n", ft_atoi_base("12FDB3", 16));
	printf("%d\n", ft_atoi_base("1010", 2));
	printf("%d\n", ft_atoi_base("0", 10));
	printf("%d\n", ft_atoi_base("-42", 10));
	printf("%d\n", ft_atoi_base("42", 10));
	printf("%d\n", ft_atoi_base("-2147483648", 10));
} */
