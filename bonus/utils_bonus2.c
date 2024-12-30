#include "ft_printf.h"

int     is_modifier(char mod)
{
    return (mod == 'c'
        || mod == 's'
        || mod == 'p'
        || mod == 'd'
        || mod == 'u'
        || mod == 'i'
        || mod == 'i'
        || mod == 'x'
        || mod == 'X'
        || mod == '%');
}

char    get_sign(t_printf *node, int *num)
{
    if (*num >= 0 && node->show_sign)
            return ('+');
    else if (*num < 0)
    {
            node->show_sign = 1;
			*num *= -1;
            return ('-');
    }
    return (0);
}

void    check_combination(t_printf *node)
{
    if (node->dot_precision > 0 && node->left_justify > 0 && node->show_sign)
        node->left_justify--;
    if (node->show_sign && node->space)
        node->space = 0;
    if (node->show_sign && node->zero_padding > 0)
        node->zero_padding--;
    if (node->show_sign && node->left_justify > 0)
        node->zero_padding--;
    if (node->width && node->zero_padding)
        node->width = 0;
    if (node->dot_precision > 0 && node->zero_padding > 0)
    {
        node->width = node->zero_padding;
        node->zero_padding = 0;
    }
    if (node->left_justify > 0 && node->zero_padding > 0)
    {
        node->left_justify = node->zero_padding;
        node->zero_padding = 0;
    }
}

