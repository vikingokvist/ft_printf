
#include "ft_printf.h"

void	ft_putchars(t_printf *node, char c)
{
	int		len;

	len = ft_strlen(node->full_str);
	node->full_str = ft_realloc(node->full_str, len + 1, len + 2);
	node->full_str[len] = c;
	node->full_str[len + 1] = '\0';
}

void	ft_putstring(t_printf *node, char *str)
{
	if (str == NULL)
		str = node->null_error;
	while (*str != '\0')
	{
		ft_putchars(node, *str);
		str++;
	}
}

void	ft_putnumber(t_printf *node, int num)
{
	char	*number;
	int		sign;

	sign = 0;
	if (num < 0)
	{
		sign = 1;
		num = -num;
	}
	number = ft_itoa(num);
	if (node->dot_precision)
		number = get_dot_precision(node, number, sign);
	if (node->left_justify)
		number = add_left_justify(node, number);
	else if (node->width)
		number = add_width(node, number);
	ft_putstring(node, number);
}

char	*get_dot_precision(t_printf *node, char *number, int sign)
{
	char	*new_num;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(number);
	new_num = malloc(len + sign + 1 * sizeof(char));
	if (!new_num)
		return (number);
	i = 0;
	if (sign)
		new_num[i++] = '-';
	while (i < node->dot_precision - len + sign)
		new_num[i++] = '0';
	j = 0;
	while (number[j])
		new_num[i++] = number[j++];
	new_num[i] = '\0';
	free(number);
	return (new_num);
}

char	*add_width(t_printf *node, char *number)
{
	char	*new_num;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(number);
	new_num = malloc(len + node->width + 1 * sizeof(char));
	if (!new_num)
		return (number);
	i = 0;
	while (i < node->width - len)
		new_num[i++] = ' ';
	j = 0;
	while (number[j])
		new_num[i++] = number[j++];
	new_num[i] = '\0';
	free(number);
	return (new_num);
}

char	*add_left_justify(t_printf *node, char *number)
{
	char	*new_num;
	int		j;
	int		i;

	new_num = malloc(node->width + 1 * sizeof(char));
	if (!new_num)
		return (number);
	i = 0;
	j = 0;
	while (number[j])
		new_num[i++] = number[j++];
	while (i < node->width)
		new_num[i++] = ' ';
	new_num[i] = '\0';
	free(number);
	return (new_num);
}

