#include "../inc/ft_printf.h"
#include <string.h>

void test_parse(char *argv) {
	argument arg = arg_parse(argv);
	printf("----------------- TEST PARSE -----------------\n");

	printf("arg.size: %8d\n", arg.size);
	printf("arg.delimiter: %3d\n", arg.delimiter);
	printf("arg.spaces: %6d\n", arg.field_size);
	printf("arg.afterpoint: %2d\n", arg.afterpoint);
	printf("arg.type: %8d\n", arg.type);

	printf("----------------------------------------------\n\n");
}

void test_parse_flags2(argument arg)
{
	printf("----------------- FLAG PARSE -----------------\n");

	printf("%-18s%s\n", "alignment: ", arg.alignment == RIGHT ? "RIGHT": "LEFT");
	printf("%-18s\'%c\'\n", "sign display: ", arg.sign_display);
	printf("%-18s\'%c\'\n", "field filling: ", arg.field_filling);
	printf("%-18s\'%s\'\n", "special chars: ", arg.special);
	printf("----------------------------------------------\n\n");
}

void test_parse_flags(char *argv)
{
	argument arg;

	arg = arg_parse(argv);
	parse_flags(argv, &arg);
	printf("----------------- FLAG PARSE -----------------\n");

	printf("%-18s%s\n", "alignment: ", arg.alignment == RIGHT ? "RIGHT": "LEFT");
	printf("%-18s\'%c\'\n", "sign display: ", arg.sign_display);
	printf("%-18s\'%c\'\n", "field filling: ", arg.field_filling);
	printf("%-18s\'%s\'\n", "special chars: ", arg.special);
	printf("----------------------------------------------\n\n");
}

void test_float(double f) {
	printf("%s\n", ft_ftoa(f, 6));
}

int		main(int argc, char **argv) {

	double f = 1.00002;
	float f1 = 1.2;
	char *test_param = "%#0+10.2fqwdqwd\n";
	char *test = malloc(10);


	// test_parse(test_param);
	// test_parse_flags(test_param);
	ft_printf(test_param, 128.22);
	printf(test_param, 128.22);
	// double f = 1.23;
	// test_float(f);
	// printf("%10f\n", 1.22);
}
