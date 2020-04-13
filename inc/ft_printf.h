#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define D	100
#define LD	101

typedef struct 	arg_params {
	int			size;
	int 		delimiter;
	char 		type;
	int			spaces;
	int			afterpoint;
	char		*data;
}				argument;

int			ft_printf(const char *format, ...);

// ARG PARSING
argument	arg_parse(const char *format);




char		*ft_ftoa(double n, int afterpoint);
int			int_to_str(long x, char str[], int d, int sign);
void		reverse_str(char *str, int len);
long		ft_pow(int x, int y);

#endif