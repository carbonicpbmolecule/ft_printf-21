#include "ft_printf.h"

unsigned short		*write_long_int(unsigned long n)
{
	int					i;
	int					len;
	unsigned short  	*result;

	len = getsize(n) + 1;
	i = 1;
	result = (unsigned short *)malloc(sizeof(unsigned short) * len);
	if (!result)
		exit(1);
	nbzero(result, len);
	result[0] = len - 1;
	while (n) {
		result[i++] = n % 10;
		n /= 10;
	}
	return (result);
}

unsigned short 		*write_double(long double d, char flag)
{
	unsigned long 		ipart;
	int 				ipart_len;
	double 				fpart;
	int 				lenght;
	unsigned 	 		res_len;
	unsigned short 		*result;
	int 				i;
	int 				tmp;

	ipart = d; 
	fpart = d - ipart;
	lenght = 0;
	if (flag)
		ipart++;
	ipart_len = getsize(ipart);
	if (!ipart_len)
	{
		ipart_len = 1;
		lenght++;
	}
	res_len = ipart_len + RIGOR + 1;
	result = (unsigned short *)malloc(sizeof(unsigned short) * res_len);
	if (!result)
		exit(1);
	nbzero(result, res_len);
	result[0] = res_len - 1;
	i = res_len - ipart_len;
	while (ipart) {
		result[i++] = ipart % 10;
		ipart /= 10;
	}
	i = res_len - ipart_len - 1;
	tmp = 0;
	while (i >= 1) {
		fpart *= 10;
		tmp = fpart;
		result[i--] = tmp;
		fpart -= tmp;
		lenght++;
	}
	return (result);
}

char 				*nbtoa1(unsigned short *c, int point, int afterpoint, int sign, char *specdot)
{
	char 				*result;
	int 				str_len;
	int 				i;
	int 				c_len;
	str_len = point - 1 + afterpoint;
	str_len += (afterpoint || *specdot) ? 1 : 0;
	str_len += (sign < 0) ? 1 : 0;

	result = (char *)malloc(sizeof(char) * str_len + 1);
	if (!result)
		exit(1);
	i = 0;
	c_len = c[0];
	if (sign < 0)
		result[i++] = '-';
	while (i < str_len)
	{
		if (!afterpoint && i == point - 1 + (sign < 0) && *specdot)
		{
			*specdot = 0;
			result[i++] = '.';
		}

		if (!afterpoint && i == point - 1 + (sign < 0))
			break ;
		if (i == point - 1 + (sign < 0))
		{
			result[i++] = '.';
		}
		result[i] = c[c_len] + '0';
		i++;
		c_len--;
	}
	*specdot = 0;
	result[str_len] = 0;
	return (result);
}

char				*round_nb(unsigned short *n, int point, int afterpoint, char sign, char *specdot)
{
	unsigned short 		number1[n[0] + 1];
	unsigned short 		number2[n[0] + 1];
	unsigned short 		*result;
	int 				power;
	int 				i;

	copy_number_0(number1, n);
	if (afterpoint == - 1)
		afterpoint = 0;
	power = n[0] - (point - 1) - afterpoint;

	i = 1;
	number2[0] = power;
	while (i < number2[0])
		number2[i++] = 0;
	number2[i] = 5;
	result = long_add(number1, number2, &point);
	return (nbtoa1(result, point, afterpoint, sign, specdot));
}
