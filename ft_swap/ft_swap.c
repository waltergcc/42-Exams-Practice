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
	int a = -12;
	int b = 1239;
	ft_swap(&a, &b);
	printf("%d - %d\n", a, b);
} */