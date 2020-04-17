#include "../inc/ft_printf.h"

static long			ft_pow(int x, int y)
{
	long result;
	long div;

	result = x;
	if (!y)
		return (1);
	div = result;
	while (--y)
		result *= div;
	return (result);
}

static void			reverse_str(char *str, int len)
{
	int 	i;
	int		j;
	int		tmp;
	
	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

static int			int_to_str(long int x, char *str, int d, int sign)
{
	int i;

	i = 0;
	if (x == 0)
		str[i++] = '0';
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x /= 10;
	}
	while (i < d)
		str[i++] = '0';
	if (sign)
		str[i++] = '-';
	reverse_str(str, i);
	str[i] = '\0';
	return (i);
}

static double		ft_round(double f, int afterpoint) {
	double	div;
	
	div = ft_pow(10, afterpoint);
	f *= div;
	f += 0.5;
	return (f / div);
}

char				*ft_ftoa(double n, int afterpoint)
{
	char		*r;
	long int	ipart;
	int			sign;
	double		fpart;

	n = ft_round(n, afterpoint);
	sign = 0;
	if (n < 0)
	{
		n = - n;
		sign = 1;
	}
	ipart = (long int)n;
	fpart = n - (double)ipart;
	r = (char *)malloc(sizeof(char) * (ft_get_nb_size(ipart) + afterpoint + 2 + sign));
	int		i = int_to_str(ipart, r, 0, sign);
	if (afterpoint != 0)
	{
		r[i] = '.';
		fpart *= ft_pow(10, afterpoint);
		int_to_str((long int)fpart, r + i + 1, afterpoint, 0);
	}
	return (r);
}
