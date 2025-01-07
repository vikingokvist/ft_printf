/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:00:56 by ctommasi          #+#    #+#             */
/*   Updated: 2025/01/07 12:00:59 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_printf(char const *str, ...)
{
	va_list		args;
	t_printf	*node;

	va_start(args, str);
	node = init_struct(NULL);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str != '\0')
			{
				init_node(node);
				str = parse_modifiers(node, (char *)str);
				call_modifiers(node, args);
			}
		}
		else
			ft_putchars(node, *str);
		str++;
	}
	free_node(node);
	va_end(args);
	return (node->len);
}

char	*parse_modifiers(t_printf *node, char *str)
{
	int		*padding;

	padding = NULL;
	while (*str != '\0' && (!is_modifier(*str) || (*str >= '0' && *str <= '9')))
	{
		if (*str == '+')
			node->show_sign = 1;
		if (*str == '#')
			node->prefixes = 1;
		if (*str == ' ')
			node->space = 1;
		if (*str == '-')
			padding = &node->left_justify;
		if (*str == '0' && padding == NULL)
			padding = &node->zero_padding;
		if (*str == '.')
			padding = &node->dot_precision;
		if (*str >= '1' && *str <= '9' && padding == NULL)
			padding = &node->width;
		if (padding != NULL)
			str = assign_padding(node, str, padding);
		node->has_flag = 1;
		str++;
	}
	node->modifier = *str;
	return (str);
}

char	*assign_padding(t_printf *node, char *str, int *padding)
{
	*padding = 0;
	if (padding != &node->width)
		str++;
	if (*str && *str >= '0' && *str <= '9')
	{
		while (*str >= '0' && *str <= '9')
		{
			*padding = (*padding * 10) + (*str - '0');
			str++;
		}
	}
	str--;
	return (str);
}

void	call_modifiers(t_printf *node, va_list args)
{
	if (node->modifier == 'c')
		ft_putchars(node, va_arg(args, int));
	else if (node->modifier == 's')
		ft_putstring(node, va_arg(args, char *));
	else if (node->modifier == 'd' || node->modifier == 'i')
		ft_putnumber(node, va_arg(args, long), 0);
	else if (node->modifier == 'u')
		ft_putnumber(node, va_arg(args, unsigned long), 1);
	else if (node->modifier == 'x')
		ft_puthex(node, node->hex_low, va_arg(args, unsigned long), 'x');
	else if (node->modifier == 'X')
		ft_puthex(node, node->hex_up, va_arg(args, unsigned long), 'X');
	else if (node->modifier == 'p')
		ft_putpointer(node, va_arg(args, void *));
	else if (node->modifier == '%')
		ft_putchars(node, '%');
}
