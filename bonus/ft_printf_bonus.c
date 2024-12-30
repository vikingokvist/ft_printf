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
		}
		else
			ft_putchars(node, *str);
		str++;
	}
	free_node(node);
	va_end(args);
	return (node->len);
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

