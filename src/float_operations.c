#include "ft_printf.h"

unsigned short	*long_pow(unsigned int nb, int power)
{
	unsigned short *a;
	unsigned short *tmp;
	unsigned short *res;

	res = write_long_int(1);
	if (power == 0)
		return res;
	a = write_long_int(nb);
	while (power--) {
		tmp = long_mult(res, a);
		free(res);
		res = tmp;
	}
	free(a);
	return (res);
}

unsigned short	*long_mult(unsigned short *a, unsigned short *b)
{
	unsigned short rlen;
	unsigned short *result;
	unsigned short cr;
	unsigned short k;
	unsigned short i;
	unsigned short j;

	rlen = a[0] + b[0] + 1;
	result = (unsigned short int *)malloc(sizeof(unsigned short int) * rlen);
	if (!result)
		exit(1);
	long_nbzero(result, rlen);
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

unsigned short	*long_add(unsigned short *a, unsigned short *b, int *point)
{
	int max;
	int c;
	int kd;
	int i;

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
