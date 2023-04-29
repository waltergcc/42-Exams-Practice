#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/* 
int	main(void)
{
	int a = 15;
	int b = 99;
	ft_swap(&a, &b);
	printf("%d - %d\n", a, b);
} */