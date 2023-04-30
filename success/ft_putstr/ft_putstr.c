#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}
/* 
int	main(void)
{
	char	s[] = "words and letters plus anything else";
	ft_putstr(s);
} */