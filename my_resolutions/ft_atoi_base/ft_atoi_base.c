#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	sign = 1;
	int	r = 0;

	if (str_base < 2 || str_base > 16)
		return (0);
		
	if (*str == '-')
	{
		sign = -1;
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
	return (sign * r);
}
/* 
int	main(void)
{
	printf("%d", ft_atoi_base("fF", 16));
} */