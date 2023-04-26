#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
/* 
int	main(void)
{
	unsigned char a = 2;
	unsigned char r = swap_bits(a);

	printf("%04d | %04d\n", (a >> 4) & 0x0F, a & 0x0F);
	printf("%04d | %04d\n", (r >> 4) & 0x0F, r & 0x0F);
} */