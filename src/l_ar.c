#include "ft_printf.h"
#define RIGOR 30

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
	unsigned long ipart = d; // 0.001015 -> 0
	double fpart = d - ipart; // 0.001015

	if (flag)
		ipart++;  // 0.001015
	unsigned int ipart_len = getsize(ipart); // 0.001015

	if (!ipart_len)
		ipart_len = 1;
	unsigned int res_len = ipart_len + RIGOR + 1;
	unsigned short *res = (unsigned short *)malloc(sizeof(unsigned short) * res_len);
	nbzero(res, res_len);

	res[0] = res_len - 1;

	int i = res_len - ipart_len;
	char ch = 0;
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
	}

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

char *nbtoa(unsigned short int *r, int point, char sign) {
	char s = 0;
	if (sign == -1)
		s = 1;

	int res_len = r[0] + 2 + s;
	char *res = (char *)malloc(sizeof(char) * res_len);

	int i = 0;
	int j = r[0];
	if (s)
		res[i++] = '-';
	while (i < res_len) {
		if (i == point + s) {
			res[i++] = '.';
			continue ;
		}
		if (i >= RIGOR) {
			res[i++] = '0';
			continue;
		}
		res[i++] = r[j--] + '0';
	}
	res[res_len-1] = 0;
	return res;
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

// unsigned short int *add_nb(unsigned short int *a, unsigned short int *b)
// {
// 	int max = (a[0] > b[0]) ? a[0] : b[0];

// 	int c = 0;
// 	int kd = 0;
// 	for (int i = 0; i < max; i++)
// 	{
// 		if (i > b[0])
// 			kd = 0;
// 		else
// 			kd = b[0];
// 		c = c + a[i] + kd;
// 		a[i] = c % 10;
// 		c = c / 10;
// 	}
// 	if (c>0)
// 	{
// 		max = max + 1;
// 		a[max] = c;
// 	}
// 	a[0] = max;
// 	return a;
// 	// print432_nb(a);
// 	// exit(1);
// }


// unsigned short *round_nb(unsigned short *n, int point, int afterpoint) {
// 	afterpoint = (!afterpoint) ? 6 : afterpoint;
// 	unsigned short *a, *b, *c, *b1, *a1;

// 	int kek = n[0] - point - afterpoint;

// 	a = cpy_nb(n);
// 	// b = pow_nb(10, kek-1);
// 	// c = add_nb(a, b);
// 	print432_nb(a);
// 	// printf("%d\n", a[0]);
// 	ft_putchar('\n');
// 	exit(1);
	
// 	// unsigned short *r = (unsigned short *)malloc(sizeof(unsigned short) * point + afterpoint + 1);
// 	// unsigned short int kek = n[0] - point - afterpoint;
// 	// unsigned short *r2;

// 	// unsigned short *b = write_long_int(5);
// 	// unsigned short *r1 = mult_nb(a, b);

// 	// if (n[kek] >= 5)
// 	// 	add_interface(a, r1);
// 	// 	// r2 = add_nb(n, r1);
// 	// else
// 	// 	r2 = n;

// 	// r[0] = point + afterpoint;
// 	// unsigned short i = r2[0];
// 	// unsigned short j = r[0];
// 	// while (j >= 1) {
// 	// 	r[j--] = r2[i--];
// 	// }

// 	// return r;
// }


