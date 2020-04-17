#include "../inc/ft_printf.h"

static int		ft_get_nb_size_hex(unsigned long int num) {
	int i = 0;
	while (num) {
		num /= 16;
		i++;
	}
	return i;
}

char	*ft_ptoa(unsigned long int address) {
	int					result_size = ft_get_nb_size_hex(address) + 2;
	int					i;
	char				*result;
	char				*hex = "0123456789abcdef";;

	result = (char *)malloc(sizeof(char) * result_size + 1);
	result[result_size] = '\0';
	i = result_size - 1;
	while (address) {
		result[i--] = hex[address % 16];
		address /= 16;
	}
	result[1] = 'x';
	result[0] = '0';
	return result;
}
