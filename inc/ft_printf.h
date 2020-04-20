#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <wchar.h>

// SIGNED
# define F	100
# define LD	101
# define I	102
# define D	103

// UNSIGNED
# define XS	105
# define XL	106
# define O	107
# define U	108
# define P	109
# define C	110
# define S	111
# define TYPES "fcspdiouxX"
# define MODS "0.#+- "

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
int			handle_invalid(const char *format, size_t *printed);

void		handle_number(argument *arg, va_list *args);
void		handle_chars(argument *arg, va_list *args);

// TEST
void test_parse_flags(argument *arg);
void test_parse(argument *arg);
char		*ft_ltoa_base(unsigned long long value, int base, int _radix_case);
char		*ft_ftoa(double n, int afterpoint);
char		*ft_itoa_base(long long value, int base, int radix_case);
char		*ft_ptoa(unsigned long int address);


//OUTPUT
int			cputchar(char c);
int			cputstr(const char *str);
#endif