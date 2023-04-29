#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
/* 
int	main(void)
{
	char a = '2';
	char b = swap_bits(a);

	printf("%04d | %04d\n", (a >> 4) & 0x0F, a & 0x0F);
	printf("%04d | %04d\n", (b >> 4) & 0x0F, b & 0x0F);
}
 */