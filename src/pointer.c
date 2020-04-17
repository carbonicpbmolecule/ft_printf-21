#include "../inc/ft_printf.h"

#define HEX "0123456789abcdef"

static int		ft_get_nb_size_hex(unsigned long int num) {
	int i = 0;
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}

char			*ft_ptoa(unsigned long int address) {
	int		result_size;
	int		i;
	char	*result;

	result_size =  ft_get_nb_size_hex(address) + 2;
	result = (char *)malloc(sizeof(char) * result_size + 1);
	result[result_size] = '\0';
	i = result_size - 1;
	while (address)
	{
		result[i--] = HEX[address % 16];
		address /= 16;
	}
	result[1] = 'x';
	result[0] = '0';
	return (result);
}
