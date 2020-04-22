#include "../inc/ft_printf.h"

int     cputchar(char c)
{
    if (c)
        write(1, &c, 1);
    return (c ? 1 : 0);
}

int     cputstr(const char *str)
{
    if (!str)
        return (0);
    if (str && *str)
    {
        ft_putstr(str);
        return(ft_strlen(str));
    }
    return (0);
}