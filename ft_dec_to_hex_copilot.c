#include "ft_printf.h"
#include "libft/libft.h"

// convert a decimal number to hexadecimal
char *ft_dec_to_hex_copilot(int d)
{
    char *hex;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    hex = (char *)malloc(sizeof(char) * (16 + 1));
    while (d > 0)
    {
        if (d % 16 > 9)
            hex[i] = d % 16 + 87;
        else
            hex[i] = d % 16 + 48;
        d = d / 16;
        i++;
    }
    while (i > 0)
    {
        hex[i] = hex[i - 1];
        i--;
    }
    hex[i] = '\0';
    return (hex);
}