#include "../inc/ft_printf.h"

char	*ft_ptoa(unsigned long int address) {
	
	unsigned long int	n;
	int					i = 14;
	char				*result;
	char				*hex;

	hex = "0123456789abcdef";
	result = (char *)malloc(sizeof(char) * 15);
	result[i--] = '\0';
	n = address;
	while (n) {
		result[i--] = hex[n % 16];
		n /= 16;
	}
	result[1] = 'x';
	result[0] = '0';
	return result;
}
