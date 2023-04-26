#include <stdio.h>
#include <stdlib.h>

void	do_op(int a, int b, char op)
{
	int r = 0;
	if (op == '+')
		r = a + b;
	else if (op == '-')
		r = a - b;
	else if (op == '*')
		r = a * b;
	else if (op == '/')
		r = a / b;
	else if (op == '%')
		r = a % b;
	printf("%d", r);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int a = atoi(av[1]);
		int b = atoi(av[3]);
		char op = av[2][0];
		if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
			do_op(a, b, op);
	}
	printf("\n");
}