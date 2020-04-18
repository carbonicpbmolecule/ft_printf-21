#include "libft.h"

void			ft_strrev(char *str, int len)
{
	int 	i;
	int		j;
	int		tmp;
	
	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}