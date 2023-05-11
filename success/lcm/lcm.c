#include <stdio.h>

int	pgcd(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (pgcd(b, a % b));
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	if ((int) a <= 0 || (int) b <= 0)
		return (0);
	else
		return ((a * b) / pgcd(a, b));
}
/* 
int	main(void)
{
	printf("%u\n", lcm(-1, 2392));
	printf("%u\n", lcm(2, 9));
} */
