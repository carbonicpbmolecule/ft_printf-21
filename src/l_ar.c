#include "ft_printf.h"
#define RIGOR 64

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

unsigned short 		*pow_nb(unsigned int nb, int power)
{
	unsigned short 		*a;
	unsigned short 		*tmp;
	unsigned short 		*res;

	res = write_long_int(1);
	if (power == 0)
		return res;
	a = write_long_int(nb);
	while (power--) {
		tmp = mult_nb(res, a);
		free(res);
		res = tmp;
	}
	free(a);
	return (res);
}

unsigned short 		*mult_nb(unsigned short *a, unsigned short *b)
{
	unsigned short	 	rlen;
	unsigned short  	*result;
	unsigned short  	cr;
	unsigned short		k;
	unsigned short		i;
	unsigned short		j;

	rlen = a[0] + b[0] + 1;
	result = (unsigned short int *)malloc(sizeof(unsigned short int) * rlen);
	if (!result)
		exit(1);
	nbzero(result, rlen);
	i = 1;
	while (i <= a[0])
	{
		j = 1;
		while (j <= b[0])
		{
			cr = a[i] * b[j];
			k = i + j - 1;
			if (cr == 0)
				result[0] = k++;
			while (cr)
			{
				cr = cr + result[k];
				result[k] = cr % 10;
				cr /= 10;
				(k > result[0]) ? result[0] = k++ : k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

void 				nbzero(unsigned short *n, unsigned short len) {
	int 				i;
	
	i = 0;
	while (i < len)
		n[i++] = 0;
}

unsigned short		*add_nb(unsigned short *a, unsigned short *b, int *point)
{
	int 				max;
	int					c;
	int 				kd;
	int 				i;
	max = (a[0] > b[0]) ? a[0] : b[0];
	c = 0;
	kd = 0;
	i = 1;
	while (i <= max)
	{
		if (i > b[0])
			kd = 0;
		else
			kd = b[i];
		c = c + a[i] + kd;
		a[i] = c % 10;
		c = c / 10;
		i++;
	}
	if (c > 0)
	{
		max = max + 1;
		*point = *point + 1;
		a[max] = c;
	}
	a[0] = max;
	return (a);
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
	result = add_nb(number1, number2, &point);
	return (nbtoa1(result, point, afterpoint, sign, specdot));
}
