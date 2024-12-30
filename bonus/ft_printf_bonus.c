/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:22:58 by ctommasi          #+#    #+#             */
/*   Updated: 2024/09/30 12:22:59 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfb(char const *str, ...)
{
	va_list	args;
	t_printf	*node;

	va_start(args, str);
	node = NULL;
	node = init_struct(node);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str != '\0')
			{
				init_node(node);
				str = init_modifiers(node, (char *)str);
				convert_modifiers(node, args);
			}
			else
				return (-1);
		}
		else
			ft_putchars(node, *str);
		str++;
	}
	for (int i=0; node->full_str[i]; i++)
		write(1, &node->full_str[i], 1);
	free_node(node);
	va_end(args);
	return (node->len);
}

char	*init_modifiers(t_printf *node, char *str)
{
	while (*str != '\0' && (!is_modifier(*str) || (*str >= '0' && *str <= '9')))
	{
		if (*str == '+')
			node->show_sign = 1;
		if (*str == '#')
			node->prefixes = 1;
		if (*str == ' ')
			node->space = 1;
		if (*str == '-')
			node->left_justify = -1;
		if (*str == '0')
			node->zero_padding = -1;
		if (*str == '.')
			node->dot_precision = -1;
		if (*str >= '1' && *str <= '9')
			node->width = -1;
		if (node->dot_precision == -1 || node->zero_padding == -1
				|| node->width == -1 || node->left_justify == -1)
			str = assign_padding(node, str);
		str++;
	}
	node->modifier = *str;
	return (str);
}

char	*assign_padding(t_printf *node, char *str)
{
	int		padding;

	padding = 0;
	if (node->width != -1)
		str++;
	if (*str && *str >= '1' && *str <= '9')
	{
		while (*str >= '0' && *str <= '9')
		{
			padding = (padding * 10) + (*str - '0');
			str++;
		}
	}
	else
		padding = -1;
	if (node->left_justify == -1)
		node->left_justify = padding;
	else if (node->dot_precision == -1)
		node->dot_precision = padding;
	else if (node->zero_padding == -1)
		node->zero_padding = padding;
	else if (node->width == -1)
		node->width = padding;
	printf("left_justify  %d\n", node->left_justify);
	printf("zero_padding  %d\n", node->zero_padding);
	printf("dot_precision %d\n", node->dot_precision);
	printf("width         %d\n", node->width);
	str--;
	return (str);
}

void	convert_modifiers(t_printf *node, va_list args)
{
	if (node->modifier == 'c')
		ft_putchars(node, va_arg(args, int));
	else if (node->modifier == 's')
		ft_putstring(node, va_arg(args, char *));
	else if (node->modifier == 'd' || node->modifier == 'i')
		ft_putnumber(node, va_arg(args, long));
	// else if (node->modifier == 'p')
	// 	ft_putptr(va_arg(args, void *));
	// else if (node->modifier == 'u')
	// 	ft_putnbr_dec(va_arg(args, long));
	// else if (node->modifier == 'x')
	// 	ft_putnbr_hex(va_arg(args, unsigned int), 0);
	// else if (node->modifier == 'X')
	// 	ft_putnbr_hex(va_arg(args, unsigned int), 1);
	// else if (node->modifier == '%')
	// 	ft_putchar('%');
}

