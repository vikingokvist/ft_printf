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

#include "../includes/libft.h"

static int	ft_format(char const format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr_dec(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbr_dec(va_arg(args, long));
	else if (format == 'x')
		len += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		len += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else
		{
			i++;
			if (!str[i])
				return (-1);
			if (str[i] != '\0')
				len += ft_format(str[i], args);
			else
				len += ft_putchar('%');
		}
		i++;
	}
	va_end(args);
	return (len);
}
