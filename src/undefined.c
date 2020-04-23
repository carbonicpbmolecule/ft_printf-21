#include "../inc/ft_printf.h"

int			is_valid_modificator(char mod)
{
	if (ft_isdigit(mod) || ft_strchr(MODS, mod))
		return (1);
	return (0);
}

int			handle_percent(const char *format, size_t *printed)
{
	int	skipped;

	skipped = 0;
	if (!format || !*format)
		return (0);
	format += 1;
	while (is_valid_modificator(*format))
	{
		skipped++;
		format++;
	}
	if (*format == '%')
	{
		*printed += cputchar('%');
		skipped++;
	}
	if (!skipped)
		return (0);
	return (skipped + 1);
}

int			handle_invalid(const char *format, size_t *printed)
{
	size_t	skipped;
	char	*tmp;

	skipped = 0;
	if (*format == '%')
	{
		tmp = ft_strtrim(format);
		if (ft_strlen(tmp) == 1)
		{
			ft_strdel(&tmp);
			return (1);
		}
		ft_strdel(&tmp);
		skipped = handle_percent(format, printed);
	}
	if (!skipped)
	{
		*printed += cputchar(*format);
		skipped++;
	}
	return (skipped);
}