/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:18:26 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/29 20:24:49 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <wchar.h>
# include <math.h>
# include <float.h>

#include <stdint.h>

#define DBLRIGOR 16

# define F	100
# define L	101
# define I	102
# define D	103

# define XS	105
# define XL	106
# define O	107
# define U	108
# define P	109
# define C	110
# define S	111
# define TYPES "fcspdiouxX"
# define FLAGS "0.#+- "

# define RIGHT 1
# define LEFT  0

typedef union
{
	double d;
	struct
	{
		unsigned long mantissa				: 52;
		unsigned int exponent				: 11;
		char sign							: 1;
	}										parts;
}											binary64;

typedef union
{
	long double ld;
	struct
	{
		unsigned long mantissa				: 64;
		unsigned int exponent				: 15;
		char sign							: 1;
	}										parts;
}											binary80;

typedef struct	s_arg_params
{
	int			size;
	int			delimiter;
	char		type;
	int			field_size;
	int			field_filling;
	int			afterpoint;
	char		alignment;
	char		sign_display;
	char		*modificator;
	char		*special;
	char		*data;
}				t_argument;

int				  		getsize(unsigned long int n);
unsigned short  		*write_long_int(unsigned long int n);
unsigned short 			*write_double(long double d, char flag);
unsigned short 			*pow_nb(unsigned int nb, int power);
unsigned short 			*mult_nb(unsigned short int *a, unsigned short int *b);
void 					nbzero(unsigned short int *n, unsigned short int len);
unsigned short int 		*add_nb(unsigned short int *a, unsigned short int *b, int *point);
void					copy_number_0(unsigned short *dest, unsigned short *src);

char					*nbtoa1(unsigned short *c, int point, int afterpoint, int sign, char *specdot);
char		 			*round_nb(unsigned short *n, int point, int afterpoint, char sign, char *specdot);

char					*ft_ftoa(double n, int afterpoint, char *specdot);
char 					*ft_lftoa(long double n, int afterpoint, char *specdot);





int				ft_printf(const char *format, ...);
t_argument		*arg_parse(const char *format);
size_t			arg_print(t_argument *arg);
int				parse_flags(const char *format, t_argument *arg);
char			*parse_modificator(t_argument *arg, const char *format);
int				valid_modificator(const char *str);
int				handle_invalid(const char *format, size_t *printed);
void			handle_pointer(t_argument *arg, va_list *args);
void			handle_number(t_argument *arg, va_list *args);
void			handle_chars(t_argument *arg, va_list *args);
char			*ft_ltoa_base(unsigned long long value, int base, int l_case);
char			*ft_itoa_base(long long value, int base, int l_case);
char			*ft_ptoa(unsigned long int address);
int				cputchar(char c);
int				cputstr(const char *str);

#endif
