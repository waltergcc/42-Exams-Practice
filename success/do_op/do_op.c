#include <stdlib.h>
#include <stdio.h>

void	do_op(int a, int b, char op)
{
	if (op == '+')
		printf("%d", a + b);
	else if (op == '-')
		printf("%d", a - b);
	else if (op == '*')
		printf("%d", a * b);
	else if (op == '/')
		printf("%d", a / b);
	else if (op == '%')
		printf("%d", a % b);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int a = atoi(av[1]);
		int b = atoi(av[3]);
		char op = av[2][0];
		do_op(a, b, op);
	}
	printf("\n");
}
