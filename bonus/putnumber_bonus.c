
#include "ft_printf.h"

void	ft_putnumber(t_printf *node, int num)
{
	char	*number;
    char    sign;

    sign = get_sign(node, &num);
	number = ft_itoa(num);
    check_combination(node);
    if (node->dot_precision)
    {
        number = add_padding(node, number, node->dot_precision, '0');
        //printf("dot_precision = %d | number = [%s]\n", node->dot_precision, number);
        node->dot_precision = 0;
    }
    if (node->zero_padding)
    {
		number = add_padding(node, number, node->zero_padding, '0');
        //printf("zero_padding = %d | number = [%s]\n", node->zero_padding, number);
        node->zero_padding = 0;
    }
	if (node->left_justify)
    {
		number = add_padding(node, number, node->left_justify, ' ');
        //printf("left_justify = %d | number = [%s]\n", node->left_justify, number);
        node->left_justify = 0;
    }
	if (node->width)
    {
		number = add_padding(node, number, node->width, ' ');
        //printf("width | number = [%s]\n", number);
        node->width = 0;
    }
    if (node->show_sign)
    {
        if (node->left_justify || node->width || node->zero_padding)
        {
            //printf("show_sign 0 = %c\n", sign);
            number = add_sign(number, sign, 0, ft_strlen(number));
        }
        else
        {
            //printf("show_sign 1 = %c\n", sign);
            number = add_sign(number, sign, 1, ft_strlen(number));
        }

    }
    ft_putstring(node, number);
}

char    *add_sign(char *number, char sign, int add_extra, int len)
{
    char    *new_num;
    int     i;
    int     j;

    new_num = malloc((len + add_extra + 1) * sizeof(char));
    if (!new_num)
        return (number);
    i = 0;
    j = 0;
    if (number[i] == '0' || number[i] != ' ')
    {
        new_num[j++] = sign;
        if (!add_extra && number[i] == '0')
            i++;
    }
    while (number[i] == ' ')
    {
        new_num[j++] = number[i++];
        if (number[i] >= '0' && number[i] <= '9')
            new_num[j - 1] = sign;
    }
    while (i < len)
        new_num[j++] = number[i++];
    new_num[len + add_extra] = '\0';
    return (free(number), new_num);
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
    if (node->left_justify && !node->dot_precision)
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
