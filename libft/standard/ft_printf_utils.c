/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:24:15 by ctommasi          #+#    #+#             */
/*   Updated: 2024/10/01 10:24:17 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (s[len] != '\0')
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	ft_putnbr_hex(unsigned long long nb, int up_or_low)
{
	int		len;
	char	hex_low;
	char	hex_up;

	len = 0;
	hex_low = "0123456789abcdef"[nb % 16];
	hex_up = "0123456789ABCDEF"[nb % 16];
	if (nb >= 16)
		len += ft_putnbr_hex(nb / 16, up_or_low);
	if (up_or_low == 0)
		len += ft_putchar(hex_low);
	else
		len += ft_putchar(hex_up);
	return (len);
}

int	ft_putnbr_dec(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		len += ft_putnbr_dec((nb / 10));
	len += ft_putchar((nb % 10) + '0');
	return (len);
}

int	ft_putptr(void *ptr)
{
	int					len;
	unsigned long long	temp;

	temp = (unsigned long long)ptr;
	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len += ft_putstr("0x");
	len += ft_putnbr_hex(temp, 0);
	return (len);
}
