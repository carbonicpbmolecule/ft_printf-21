#include "ft_printf.h"

void show_mem_a(unsigned short *a, int flag)
{
	int i = 1;
	printf("%d |", a[0]);
	while (i <= a[0])
		printf("%d", a[i++]);
	printf("\n");
	if (flag)
		exit(1); 
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
	long_nbzero(result, len);
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
	long_nbzero(result, res_len);
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

int write_ipart(char *dest, t_sme *n)
{
	int i;
	int j;
	int len;

	i = 0;
	j = n->rounded[0];
	len = n->point - 1;
	if (n->sign == -1)
		dest[i++] = '-';
	while (len)
	{
		dest[i++] = n->rounded[j--] + '0';
		len--;
	}
	dest[i] = 0;
	return (i);
}

int write_fpart(char *dest, int i, t_sme *n)
{
	int len = n->rounded[0];
	int counter = 0;
	int ipart = i;
	int j = n->sign == - 1 ? 2 : 1;
	while (counter < n->afterpoint)
	{
		if (counter >= n->rounded[0] - ipart)
		{
			dest[i++] = '0';
			counter++;
			continue;
		}
		dest[i] = n->rounded[len-i+j] + '0';
		i++;
		counter++;
	}
	dest[i] = 0;
	return (i);
}

char 				*nbtoa1(t_sme *n, char *specdot)
{
	char 				*result;
	int 				str_len;
	int					wr;
	int					end;

	str_len = n->point - 1 + n->afterpoint;
	str_len += (n->afterpoint || *specdot) ? 1 : 0;
	str_len += (n->sign < 0) ? 1 : 0;

	result = (char *)malloc(sizeof(char) * str_len + 1);
	if (!result)
		exit(1);
	wr = write_ipart(result, n);
	if (n->afterpoint)
	{
		result[wr++] = '.';
		result[wr] = 0;
	}
	end = write_fpart(result, wr, n);
	if (*specdot && !n->afterpoint)
	{
		result[end] = '.';
		result[end+1] = 0;
	}
	*specdot = 0;
	return (result);
}

void get_term(t_sme *n, unsigned short *num)
{
	int term;
	int i;
	int ipart;
	int fpart;

	ipart = n->point - 1;
	fpart = (n->afterpoint > n->result[0] - ipart) ? n->result[0] - ipart : n->afterpoint;
	term = n->result[0] - ipart - fpart;
	i = 1;
	num[0] = term;
	while (i < num[0])
		num[i++] = 0;
	num[i] = 5;
}

char				*long_round(t_sme *n, char *specdot)
{
	unsigned short 		number1[n->result[0] + 1];
	unsigned short 		number2[n->result[0] + 1];

	char *final;
	long_nbcopy(number1, n->result);
	get_term(n, number2);
	n->rounded = long_add(number1, number2, &n->point);
	final = nbtoa1(n, specdot);
	return (final);
}
