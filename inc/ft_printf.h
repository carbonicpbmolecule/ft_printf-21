#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// SIGNED
# define F	100
# define LD	101
# define I	102
# define D	103

// UNSIGNED
# define XS	105
# define XL	106
# define O	107
# define S	108
# define U	109
# define P	110
# define C	111
# define TYPES "fcspdiouxX"

# define RIGHT 1
# define LEFT  0

typedef struct 	arg_params {
	int			size;
	int 		delimiter;
	char 		type;
	int			field_size;
	int			field_filling;
	int			afterpoint;
	char		alignment;
	char		sign_display;
	char		*modificator;
	char		*special;
	char		*data;
}				argument;

int			ft_printf(const char *format, ...);

// ARG PARSING
argument	*arg_parse(const char *format);
int			parse_flags(const char *format, argument *arg);
char		*parse_modificator(argument *arg, const char *format);

// TEST
void test_parse_flags(argument *arg);
void test_parse(argument *arg);

char		*ft_ftoa(double n, int afterpoint);
char		*ft_itoa_base(int value, int base, int radix_case);
int			int_to_str(long x, char str[], int d, int sign);
void		reverse_str(char *str, int len);
long		ft_pow(int x, int y);
double 		ft_round(double f, int aft);

#endif