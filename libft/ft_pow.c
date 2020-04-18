#include "libft.h"

long			ft_pow(double n, int pow) {
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}
