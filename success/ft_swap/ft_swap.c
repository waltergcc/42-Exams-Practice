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
	int a = 1;
	int b = 15;
	ft_swap(&a, &b);
	printf("%d %d", a, b);
} */