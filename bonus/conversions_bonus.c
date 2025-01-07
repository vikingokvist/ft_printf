/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:00:28 by ctommasi          #+#    #+#             */
/*   Updated: 2025/01/07 12:00:33 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	convert_modifiers(t_printf *node, char sign)
{
	if (node->dot_precision)
		node->result = add_padding(node, &node->dot_precision, '0');
	if (node->prefixes && (node->modifier == 'x'
			|| node->modifier == 'X' || node->modifier == 'p'))
		node->result = add_prefix(node, sign);
	if (node->zero_padding)
		node->result = add_padding(node, &node->zero_padding, '0');
	if (node->left_justify)
		node->result = add_padding(node, &node->left_justify, ' ');
	if (node->width)
		node->result = add_padding(node, &node->width, ' ');
	if (node->show_sign)
	{
		if (node->left_justify || node->width || node->zero_padding)
			node->result = add_sign(node, sign, 0, ft_strlen(node->result));
		else
			node->result = add_sign(node, sign, 1, ft_strlen(node->result));
	}
	else if (node->space)
		node->result = add_sign(node, ' ', 1, ft_strlen(node->result));
}

char	*add_sign(t_printf *node, char sign, int add_extra, int len)
{
	char	*new_num;
	int		i;
	int		j;

	new_num = malloc((len + add_extra + 1) * sizeof(char));
	if (!new_num)
		return (node->result);
	i = 0;
	j = 0;
	if (node->result[i] == '0' || node->result[i] != ' ')
	{
		new_num[j++] = sign;
		if (!add_extra && node->result[i] == '0')
			i++;
	}
	while (node->result[i] == ' ')
	{
		new_num[j++] = node->result[i++];
		if (ft_is_hex_or_num(node->result[i]))
			new_num[j - 1] = sign;
	}
	while (i < len)
		new_num[j++] = node->result[i++];
	new_num[len + add_extra] = '\0';
	return (free(node->result), new_num);
}

char	*add_padding(t_printf *node, int *padding_type, char c)
{
	char	*new_num;
	int		len;
	int		padding;

	len = ft_strlen(node->result);
	padding = *padding_type - len;
	if (padding < 0)
		padding = 0;
	new_num = malloc((len + padding + 1) * sizeof(char));
	if (!new_num)
		return (node->result);
	fill_padding(node, new_num, c, padding);
	free(node->result);
	*padding_type = 0;
	return (new_num);
}

void	fill_padding(t_printf *node, char *new_num, char c, int padding)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (node->left_justify && !node->dot_precision)
	{
		while (node->result[j])
			new_num[i++] = node->result[j++];
		while (padding-- > 0)
			new_num[i++] = c;
	}
	else
	{
		while (i < padding)
			new_num[i++] = c;
		while (node->result[j])
			new_num[i++] = node->result[j++];
	}
	new_num[i] = '\0';
}

char	*add_prefix(t_printf *node, char sign)
{
	char	*new_str;

	if (sign == 'x')
	{
		new_str = ft_strjoin("0x", node->result);
		if (!new_str)
			return (node->result);
	}
	else
	{
		new_str = ft_strjoin("0X", node->result);
		if (!new_str)
			return (node->result);
	}
	free(node->result);
	return (new_str);
}
