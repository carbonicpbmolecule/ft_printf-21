#include "ft_printf.h"
#define RIGOR 30

void show_mem_a(unsigned short *a, int flag)
{
	int i = 0;
	while (i <= a[0]){
		printf("%d", a[i++]);
		if (i-1 == 0)
			printf("|");
	}
	printf("\n");
	if (flag)
		exit(1);
}

unsigned short int *write_long_int(unsigned long int n) {
	unsigned short int i = 1;
	unsigned short int len = getsize(n) + 1;
	unsigned short int *r = (unsigned short int *)malloc(sizeof(unsigned short int) * len);

	nbzero(r, len);

	r[0] = len - 1;

	while (n) {
		r[i++] = n % 10;
		n /= 10;
	}
	return r;
}

unsigned short int getsize(unsigned long int n) {
	unsigned short int size = 0;
	while (n) {
		n /= 10;
		size++;
	}
	return size;
}

unsigned short *write_double(double d, char flag) {
	unsigned long ipart = d; 
	double fpart = d - ipart;
	int lenght = 0;

	if (flag)
		ipart++;
	unsigned int ipart_len = getsize(ipart);

	if (!ipart_len)
	{
		ipart_len = 1;
		lenght++;
	}
	unsigned int res_len = ipart_len + RIGOR + 1;
	unsigned short *res = (unsigned short *)malloc(sizeof(unsigned short) * res_len);
	nbzero(res, res_len);

	res[0] = res_len - 1;

	int i = res_len - ipart_len;
	// char ch = 0;
	while (ipart) {
		res[i++] = ipart % 10;
		ipart /= 10;
	}
	i = res_len - ipart_len - 1;
	unsigned short tmp = 0;
	while (i >= 1) {
		fpart *= 10;
		tmp = fpart;
		res[i--] = tmp;
		fpart -= tmp;
		lenght++;
	}
	// printf("%d\n", lenght);
	// exit(1);
	// show_mem_a(res, 1);
	return res;
}

unsigned short *pow_nb(unsigned int nb, int power) {
	unsigned short *res, *tmp;
	unsigned short *a;

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
	return res;
}

unsigned short *mult_nb(unsigned short int *a, unsigned short int *b)
{
	unsigned short int rlen = a[0] + b[0] + 1;
	unsigned short int *r = (unsigned short int *)malloc(sizeof(unsigned short int) * rlen);
	nbzero(r, rlen);
	unsigned short int cr, k, i, j;

	i = 1;
	while (i <= a[0])
	{
		j = 1;
		while (j <= b[0])
		{
			cr = a[i] * b[j];
			k = i + j - 1;
			if (cr == 0)
				r[0] = k++;
			while (cr)
			{
				cr = cr + r[k];
				r[k] = cr % 10;
				cr /= 10;
				(k > r[0]) ? r[0] = k++ : k++;
			}
			
			j++;
		}
		i++;
	}
	return r;
}

void nbzero(unsigned short int *n, unsigned short int len) {
	unsigned  short int i = 0;
	while (i < len)
		n[i++] = 0;
}

void print432_nb(unsigned short int *r)
{
	unsigned short int len = r[0];
	unsigned short int i = 0;
	char *str = (char *)malloc(sizeof(char) * len + 1);

	while (len)
		str[i++] = r[len--] + '0';

	write(1, str, r[0]);

	free(str);
}

unsigned short int *add_nb(unsigned short int *a, unsigned short int *b, int *point) {
	int max = (a[0] > b[0]) ? a[0] : b[0];

	int c = 0;
	int kd = 0;

	for (int i = 1; i <= max; i++)
	{
		c = c + a[i] + b[i];
		a[i] = c % 10;
		c = c / 10;
	}
	if (c > 0)
	{
		max = max + 1;
		*point = *point + 1;
		a[max] = c;
	}
	a[0] = max;
	return a;
}

unsigned short *cpy_nb(unsigned short *n)
{
	int len = 100;
	
	unsigned short *a = (unsigned short *)malloc(sizeof(unsigned short) * len);
	nbzero(a, len);
	a[0] = n[0];
	int j = 1;
	int i = 1;

	while (j <= n[0])
		a[i++] = n[j++];
	return a;
}

char *nbtoa1(unsigned short *c, int point, int afterpoint, int sgn)
{
	int final_len = point + 1 + afterpoint + sgn;
	printf("%d : sign %d\n", final_len, sgn);
	char *final = (char *)malloc(sizeof(char) * final_len + 1);
	final[final_len] = 0;
	int i = 0;

	int len = c[0];
	// printf("%d\n", c[len]);
	show_mem_a(c, 0);
	if (sgn)
		final[i++] = '-';
	while (i < final_len)
	{
		if (i == point)
			final[i++] = '.';
		final[i++] = c[len--] + '0';
	}
	
	printf("%s\n", final);
	exit(1);
}

char *round_nb(unsigned short *n, int point, int afterpoint, char sign)
{
	int sgn = 0;
	if (sign == -1)
		sgn = 1;
	afterpoint = (!afterpoint) ? 6 : afterpoint;
	int rounded = n[0] - point - afterpoint;
	
	unsigned short *a, *b, *b1, *c;

	a = cpy_nb(n);
	b = pow_nb(10, rounded-1);
	b1 = cpy_nb(b);
	c = add_nb(a, b1, &point);
	// printf("%d\n", point);
	// show_mem_a(c, 1);
	return nbtoa1(c, point, afterpoint, sgn);
}