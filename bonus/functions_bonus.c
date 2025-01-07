/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:01:17 by ctommasi          #+#    #+#             */
/*   Updated: 2025/01/07 12:01:19 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_putchars(t_printf *node, char c)
{
	check_char_combination(node);
	node->result = malloc(2);
	if (!node->result)
		return ;
	node->result[0] = c;
	node->result[1] = '\0';
	convert_modifiers(node, 0);
	ft_putstring(node, node->result, 0);
}

void	ft_putstring(t_printf *node, char *str, int mode)
{
	if (str == NULL)
		str = node->null_error;
	if (mode)
	{
		node->result = ft_strdup(str);
		convert_modifiers(node, 0);
		str = ft_strdup(node->result);
		free(node->result);
	}
	while (*str != '\0')
	{
		ft_printchars(node, *str);
		str++;
	}
}

void	ft_putnumber(t_printf *node, int num, int un_sign)
{
	char			sign;
	unsigned int	unum;

	sign = 0;
	if (node->has_flag && num == 0 && !has_flag(node))
		return ;
	if (!un_sign)
	{
		if (num >= 0 && node->show_sign)
			sign = '+';
		else if (num == -2147483648)
		{
			node->show_sign = 0;
			num = ((num + 1) * -1) + 1;
		}
		else if (num < 0)
		{
			node->show_sign = 1;
			num = -num;
			sign = '-';
		}
		node->result = ft_itoa(num);
	}
	else
	{
		unum = (unsigned int)num;
		node->result = ft_uitoa(unum);
	}
	check_combination(node);
	convert_modifiers(node, sign);
	ft_putstring(node, node->result, 0);
}

void	ft_puthex(t_printf *node, char *hex, unsigned long nb, char prefix)
{
	int				len;
	unsigned long	len_nb;

	len_nb = nb;
	len = 1;
	while (len_nb >= 16 && ++len)
		len_nb /= 16;
	node->result = malloc((len + 1) * sizeof(char));
	if (!node->result)
		return ;
	node->result[len--] = '\0';
	if (nb == 0)
		node->result[len] = '0';
	while (nb)
	{
		node->result[len--] = hex[nb % 16];
		nb /= 16;
	}
	convert_modifiers(node, prefix);
	ft_putstring(node, node->result, 0);
}

void	ft_putpointer(t_printf *node, void *ptr)
{
	unsigned long long	temp;

	temp = (unsigned long long)ptr;
	if (!ptr)
	{
		ft_putstring(node, node->nil_error, 0);
		return ;
	}
	node->prefixes = 1;
	ft_puthex(node, node->hex_low, temp, 1);
}
