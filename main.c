#include "inc/ft_printf.h"

int		main() {
	float f = 3.22;

	printf("arg1: %f; arg2: %10f, arg3: %10.4f\n", 1.2, 2.2, 3.2);

	ft_printf("arg1: %f; arg2: %10f, arg3: %10.4f\n", 1.2, 2.2, 3.2);

}