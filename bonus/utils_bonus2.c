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
    else if (*num == -2147483648)
    {
        node->show_sign = 0;
        (*num)++;
        *num *= -1;
        (*num)++;
        return (0);
    }
    else if (*num < 0)
    {
        node->show_sign = 1;
		*num = -(*num);
        return ('-');
    }
    return (0);
}

void    check_combination(t_printf *node)
{
    if (node->zero_padding > 0)
    {
        if (node->space && !node->show_sign)
            node->zero_padding--;
        if (node->show_sign && !node->dot_precision)
            node->zero_padding--;
        if (node->width > 0)
            node->width = 0;
        if (node->dot_precision > 0)
        {
            node->width = node->zero_padding;
            node->zero_padding = 0;
        }
        if (node->left_justify > 0)
        {
            node->left_justify = node->zero_padding;
            node->zero_padding = 0;
        }
    }
    if (node->show_sign && node->space)
        node->space = 0;
    if (node->left_justify > 0 && node->show_sign)
        node->left_justify--;
}
