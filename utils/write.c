#include "../inc/ft_printf.h"

int     cputchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int     cputstr(const char *str)
{
    ft_putstr(str);
    return (ft_strlen(str));
}