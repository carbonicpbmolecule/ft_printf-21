/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:18:26 by acyrenna          #+#    #+#             */
/*   Updated: 2020/05/13 17:16:57 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

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

# define DBLRIGOR 16
# define RIGOR 64
# define OFFSETBIN64 1023
# define OFFSETBIN80 16383

/*
** Struct for double
*/
typedef union			u_binary64
{
	double				d;
	struct
	{
		unsigned long	mantis: 52;
		unsigned int	exp: 11;
		char			sign: 1;
	}					s_parts;
}						t_binary64;

/*
** Struct for long double
*/
typedef union			u_binary80
{
	long double			ld;
	struct
	{
		unsigned long	mantis: 64;
		unsigned int	exp: 15;
		char			sign: 1;
	}					s_parts;
}						t_binary80;

typedef struct			s_sme
{
	int					denorm;
	unsigned short		*part1;
	unsigned short		*part2;
	unsigned short		*result;
}						t_sme;

/*
** Main struct for arguments representation
*/
typedef struct			s_arg_params
{
	int					size;
	int					delimiter;
	char				type;
	int					field_size;
	int					field_filling;
	int					afterpoint;
	char				alignment;
	char				sign_display;
	char				*modificator;
	char				*special;
	char				*data;
}						t_argument;

/*
** Long arithmetic functions
*/
char					*ftoa(double n, int afterpoint, char *specdot);
char 					*lftoa(long double n, int afterpoint, char *specdot);
char					*long_ltoa(unsigned short *c, int point, int afterpoint, int sign);
char		 			*long_round(unsigned short *n, int point, int afterpoint, char sign);
unsigned short 			*long_write_double(long double d, char flag);
unsigned short  		*long_write_long_int(unsigned long int n);
unsigned short 			*long_mult(unsigned short int *a, unsigned short int *b);
unsigned short 			*long_pow(unsigned int nb, int power);
unsigned short int 		*long_add(unsigned short int *a, unsigned short int *b, int *point);
int				  		getsize(unsigned long int n);
void 					long_nbzero(unsigned short int *n, unsigned short int len);
void					long_nbcopy(unsigned short *dest, unsigned short *src);

/*
** The stupid content printer
*/
int						ft_printf(const char *format, ...);

/*
** Some specific 'atois' for representing long numbers
*/
char					*ft_ltoa_base(unsigned long long value, int base, int\
																		l_case);
char					*ft_itoa_base(long long value, int base, int l_case);

/*
** Printing functions
*/
size_t					arg_print(t_argument *arg);
int						cputchar(char c);
int						cputstr(const char *str);

/*
** Parsing functioncs in formating string
*/
int						parse_flags(const char *format, t_argument *arg);
char					*parse_modificator(t_argument *arg, const char *format);
int						valid_modificator(const char *str);
t_argument				*arg_parse(const char *format);

/*
** Conversations handlers
*/
int						handle_invalid(const char *format, size_t *printed);
void					handle_pointer(t_argument *arg, va_list *args);
void					handle_number(t_argument *arg, va_list *args);
void					handle_chars(t_argument *arg, va_list *args);
#endif
