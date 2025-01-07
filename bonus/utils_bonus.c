/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:01:36 by ctommasi          #+#    #+#             */
/*   Updated: 2025/01/07 12:01:38 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	has_flag(t_printf *node)
{
	return (node->dot_precision
		|| node->left_justify
		|| node->zero_padding
		|| node->width
		|| node->prefixes
		|| node->space
		|| node->prefixes
		|| node->show_sign);
}

int	is_modifier(char mod)
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

int	ft_is_hex_or_num(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'));
}

void	check_combination(t_printf *node)
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

void	check_char_combination(t_printf *node)
{
	if (node->zero_padding)
	{
		node->width = node->zero_padding;
		node->zero_padding = 0;
	}
	node->show_sign = 0;
	node->space = 0;
	node->dot_precision = 0;
	node->prefixes = 0;
}