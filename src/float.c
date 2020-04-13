#include "../inc/ft_printf.h"

long		ft_pow(int x, int y)
{
	long result = x;
	if (!y)
		return 1;
	long div = result;
	while (--y)
		result *= div;
	return result;
}

void	reverse_str(char *str, int len)
{
	int i = 0, j = len - 1, tmp;
	while (i < j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int		int_to_str(long int x, char *str, int d, int sign)
{
	int i = 0;
	if (x == 0)
		str[i++] = '0';
	while (x) {
		str[i++] = (x % 10) + '0';
		x /= 10;
	}
	while (i < d)
		str[i++] = '0';
	if (sign)
		str[i++] = '-';
	reverse_str(str, i);
	str[i] = '\0';
	return i;
}

char	*ft_ftoa(double n, int afterpoint)
{
	char		*r;
	long int	ipart;
	int			sign = 0;
	double		fpart;

	if (n < 0) {
		n = - n;
		sign = 1;
	}
	ipart = (long int)n;
	fpart = n - (double)ipart;
	r = (char *)malloc(sizeof(char) * (ft_get_nb_size(ipart) + afterpoint + 2 + sign));

	int		i = int_to_str(ipart, r, 0, sign);

	if (afterpoint != 0) {
		r[i] = '.';
		fpart *= ft_pow(10, afterpoint);
		int_to_str((long int)fpart, r + i + 1, afterpoint, 0);
	}
	return r;
}
