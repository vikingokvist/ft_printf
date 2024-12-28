
#include "ft_printf.h"

void	ft_putnumber(t_printf *node, int num)
{
	char	*number;
    char    sign;

    if (node->sign && num >= 0)
        sign = '+';
	else if (num < 0)
	{
        node->sign = 1;
        sign = '-';
		num = -num;
	}
	number = ft_itoa(num);
    if (node->dot_precision && node->zero_padding)
    {
        number = add_padding(node, number, node->dot_precision, '0');
        number = add_padding(node, number, node->zero_padding, ' ');
    }
	else if (node->dot_precision && !node->zero_padding)
    {
		number = add_padding(node, number, node->dot_precision, '0');
    }
    else if (!node->dot_precision && node->zero_padding)
    {
		number = add_padding(node, number, node->zero_padding, '0');
    }
	if (node->left_justify)
    {
		number = add_padding(node, number, node->left_justify, ' ');
    }
	else if (node->width)
    {
		number = add_padding(node, number, node->width, ' ');
    }
    if (node->sign)
    {
        if (!node->zero_padding)
            number = add_sign(number, sign, 1);
        else
            number = add_sign(number, sign, 0);
    }
	ft_putstring(node, number);
}

char    *add_sign(char *number, char sign, int add_extra)
{
    char    *new_num;
    int     len;
    int     i;
    int     j;

    len = ft_strlen(number) + add_extra;
    new_num = malloc((len + 1) * sizeof(char));
    if (!new_num)
        return (number);
    i = 0;
    j = 0;
    if (number[i] == '0')
    {
        new_num[j++] = sign;
        i = !add_extra;
    }
    while (number[i] == ' ')
    {
        new_num[j++] = number[i++];
        if (number[i] >= '0' && number[i] <= '9')
            new_num[j - 1] = sign;
    }
    while (i < len)
        new_num[j++] = number[i++];
    new_num[i] = '\0';
    free(number);
    return (new_num);
}

char	*add_padding(t_printf *node, char *number, int padding_type, char c)
{
	char	*new_num;
	int		len;
    int     padding;

	len = ft_strlen(number);
    padding = padding_type - len;
    if (padding < 0)
        padding = 0;
    new_num = malloc((len + padding + 1) * sizeof(char));
	if (!new_num)
		return (number);
    if (node->left_justify)
    {
        fill_padding_left(new_num, number, c, padding);
    }
    else
    {
        fill_padding_right(new_num, number, c, padding);
    }
	free(number);
	return (new_num);
}

void    fill_padding_right(char *new_num, char *number, char c, int padding)
{
    int     i;
    int     j;

    i = 0;
    while (i < padding)
		new_num[i++] = c;
	j = 0;
	while (number[j])
		new_num[i++] = number[j++];
    new_num[i] = '\0';
}

void    fill_padding_left(char *new_num, char *number, char c, int padding)
{
    int     i;
    int     j;

    j = 0;
    i = 0;
    while (number[j])
		new_num[i++] = number[j++];
	while (padding-- > 0)
		new_num[i++] = c;
    new_num[i] = '\0';
}
