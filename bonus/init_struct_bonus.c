/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:01:51 by ctommasi          #+#    #+#             */
/*   Updated: 2025/01/07 12:01:53 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*init_struct(t_printf *node)
{
	node = (t_printf *)malloc(sizeof(t_printf));
	if (!node)
		return (NULL);
	node->null_error = ft_strdup("(null)");
	node->nil_error = ft_strdup("(nil)");
	node->hex_up = ft_strdup("0123456789ABCDEF");
	node->hex_low = ft_strdup("0123456789abcdef");
	node->full_str = ft_strdup("");
	node->len = 0;
	return (node);
}

void	init_node(t_printf *node)
{
	node->has_flag = 0;
	node->prefixes = 0;
	node->space = 0;
	node->show_sign = 0;
	node->width = 0;
	node->dot_precision = 0;
	node->left_justify = 0;
	node->zero_padding = 0;
	node->modifier = 0;
	if (node->result)
		free(node->result);
	node->result = NULL;
}

void	free_node(t_printf *node)
{
	if (node->full_str)
	{
		free(node->full_str);
	}
	if (node->nil_error)
	{
		free(node->nil_error);
	}
	if (node->null_error)
	{
		free(node->null_error);
	}
	if (node->hex_low)
	{
		free(node->hex_low);
	}
	if (node->hex_up)
	{
		free(node->hex_up);
	}
	free(node);
}
