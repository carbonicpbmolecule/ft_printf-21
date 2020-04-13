#include "../inc/ft_printf.h"

void test_parse(char *argv) {
	argument arg = arg_parse(argv);
	printf("----------------- TEST PARSE -----------------\n");

	printf("arg.size: %8d\n", arg.size);
	printf("arg.delimiter: %3d\n", arg.delimiter);
	printf("arg.spaces: %6d\n", arg.spaces);
	printf("arg.afterpoint: %2d\n", arg.afterpoint);
	printf("arg.type: %8d\n", arg.type);

	printf("----------------------------------------------\n");
}

void test_float(double f) {
	printf("%s\n", ft_ftoa(f, 6));
}

int		main(int argc, char **argv) {

	double f = 1.00002;
	float f1 = 1.2;
	test_parse(argv[1]);

	// double f = 1.23;
	// test_float(f);
	// printf("%10f\n", 1.22);
}