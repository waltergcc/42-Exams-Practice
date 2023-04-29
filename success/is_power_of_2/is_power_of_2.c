#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n != 1)
	{
		if (n % 2 != 0)
			return (0);
		n /= 2;
	}
	return (1);
	
}
/* 
int	main(void)
{
	printf("%d\n", is_power_of_2(0));
	printf("%d\n", is_power_of_2(1));
	printf("%d\n", is_power_of_2(2));
	printf("%d\n", is_power_of_2(4));
	printf("%d\n", is_power_of_2(64));
	printf("%d\n", is_power_of_2(13));
	printf("%d\n", is_power_of_2(100));
} */
