#include "ft_printf.h"

char 			*ftoa(double n, int afterpoint, char *specdot)
{
	t_binary64		d;
	t_sme			sme;
	char			*final;
	double			d_part1;

	d.d = n;
	// printf("%d\n", sme.afterpoint); exit(1);
	if (afterpoint == -1)
		afterpoint = 0;
	sme.afterpoint = (afterpoint < 0) ? -afterpoint : afterpoint;
	final = check_nan_inf64(d, n);
	if (final)
		return final;
	sme.point = 0;
	sme.sign = d.s_parts.sign;
	sme.denorm = d.s_parts.exp < OFFSETBIN64;
	if (sme.denorm)
	{
		d_part1 = ft_power(2, d.s_parts.exp - OFFSETBIN64);
		sme.part1 = write_double(d_part1, 0);
	}
	else
		sme.part1 = long_pow(2, d.s_parts.exp - OFFSETBIN64);
	sme.part2 = write_double(d.s_parts.mantis / ft_power(2, 52), 1);
	sme.result = long_mult(sme.part1, sme.part2);
	sme.point = sme.denorm ? 2 : sme.result[0] - sme.part2[0] + 2;
	final = long_round(&sme, specdot);
	free(sme.part1);
	free(sme.part2);
	free(sme.result);
	return (final);
}

char 			*lftoa(long double n, int afterpoint, char *specdot)
{
	t_binary80		ld;
	t_sme			sme;
	int				point;
	long double		d_part1;
	char			*final;

	ld.ld = n;
	final = check_nan_inf80(ld, n);
	if (final)
		return final;
	point = 0;
	sme.denorm = ld.s_parts.exp < OFFSETBIN80;
	if (sme.denorm)
	{
		d_part1 = ft_power_l(2, ld.s_parts.exp - OFFSETBIN80);
		sme.part1 = write_double(d_part1, 0);
	}
	else
		sme.part1 = long_pow(2, ld.s_parts.exp - OFFSETBIN80);
	sme.part2 = write_double(ld.s_parts.mantis / ft_power(2, 63), 0);
	sme.result = long_mult(sme.part1, sme.part2);
	point = sme.denorm ? 2 : sme.result[0] - sme.part2[0] + 2;
	final = long_round(&sme, specdot);
	free(sme.part1);
	free(sme.part2);
	free(sme.result);
	return (final);
}
