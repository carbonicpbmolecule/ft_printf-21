#include "../inc/ft_printf.h"

char g_modificators[5][3] = {"hh", "h", "ll", "l", "L"};
# define MODIFICATORS_LEN 5

int valid_modificator(char *str)
{
    size_t i;

    i = 0;
    if (!str || !*str)
        return (0);
    while (i < MODIFICATORS_LEN && g_modificators[i])
    {
        if (ft_strcmp(g_modificators[i], str) == 0)
            return (1);
        i++;
    }
    return (0);
}

void parse_modificator(char *format)
{

}

// int main()
// {
//     char *hh = "hh";
//     char *invalid = "ww";

//     printf("hh -> %d\n", valid_modificator(hh));
//     printf("invalid -> %d\n", valid_modificator(invalid));
// }