#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_nbrlen(long n)
{
	int i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int ft_hexlen(unsigned int n)
{
	int i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void ft_putnbr(long n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void ft_puthex(unsigned int n)
{
	char *hex = "0123456789abcdef";
	if (n >= 16)
		ft_puthex(n / 16);
	ft_putchar(hex[n % 16]);
}

int print_str(char *s)
{
 	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(s);
	return (ft_strlen(s));
}

int print_nbr(int n)
{
	ft_putnbr(n);
	return (ft_nbrlen(n));
}

int print_hex(unsigned int n)
{
	ft_puthex(n);
	return (ft_hexlen(n));
}

int ft_formats(va_list args, const char *s)
{
	int i = 0;
	if (*s == 's')
		i += print_str(va_arg(args, char *));
	else if (*s == 'd')
		i += print_nbr(va_arg(args, int));
	else if (*s == 'x')
		i += print_hex(va_arg(args, unsigned int));
	return (i);
}

int ft_printf(const char *str, ... )
{
	va_list args;
	va_start(args, str);
	int i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += ft_formats(args, str);
		}
		else
		{
			ft_putchar(*str);
			i++;
		}
		str++;
	}
	va_end(args);
	return (i);
}
/* 
int main(void)
{
	char s[] = "Hello, World!";
	char *sn = NULL;
	int n1 = INT_MAX;
	int n2 = INT_MIN;
	int n3 = 0;
	int or = 0;
	int ft = 0;

	or = printf("%s\n", s);
	printf("%d\n", or);
	ft = ft_printf("%s\n", s);
	ft_printf("%d\n", ft);

	or = printf("%s\n", sn);
	printf("%d\n", or);
	ft = ft_printf("%s\n", sn);
	ft_printf("%d\n", ft);

	or = printf("%d %d %d\n", n1, n2, n3);
	printf("%d\n", or);
	ft = ft_printf("%d %d %d\n", n1, n2, n3);
	ft_printf("%d\n", ft);

	or = printf("%x %x %x\n", n1, n2, n3);
	printf("%d\n", or);
	ft = ft_printf("%x %x %x\n", n1, n2, n3);
	ft_printf("%d\n", ft);

	or = printf("This is a test for %s %s, %d %d %d and %x %x %x\n", s, sn, n1, n2, n3, n1, n2, n3);
	printf("%d\n", or);
	ft = ft_printf("This is a test for %s %s, %d %d %d and %x %x %x\n", s, sn, n1, n2, n3, n1, n2, n3);
	ft_printf("%d\n", ft);
} */