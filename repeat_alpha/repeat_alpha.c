#include <unistd.h>

int	getIndex(char c)
{
	int r = 0;
	if (c >= 'a' && c <= 'z')
		r = c - 'a';
	else if (c >= 'A' && c <= 'Z')
		r = c - 'A';
	return (r);
}

void	repeat_alpha(char *s)
{
	int i = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			int size = getIndex(s[i]) + 1;
			while (size > 0)
			{
				write(1, &s[i], 1);
				size--;
			}
		}
		else
			write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		repeat_alpha(av[1]);
	}
	write(1, "\n", 1);
}