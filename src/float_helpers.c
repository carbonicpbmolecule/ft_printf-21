#include "ft_printf.h"

int					getsize(unsigned long n) {
	int				size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void 				nbzero(unsigned short *n, unsigned short len) {
	int 				i;

	i = 0;
	while (i < len)
		n[i++] = 0;
}

void				copy_number_0(unsigned short *dest, unsigned short *src)
{
	int 				i;
	int 				j;

	j = 1;
	i = 1;
	dest[0] = src[0];
	while (j <= dest[0])
		dest[i++] = src[j++];
}
