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
	ft_putstring(node, node->result);
}

void	ft_putstring(t_printf *node, char *str)
{
	if (str == NULL)
		str = ft_strdup(node->null_error);
	while (*str != '\0')
	{
		ft_printchars(node, *str);
		str++;
	}
	free(node->result);
	node->result = NULL;
}

void	ft_putnumber(t_printf *node, int num, int un_sign)
{
	char			sign;

	sign = 0;
	if (node->has_flag && num == 0 && !has_flag(node))
		return ;
	if (num >= 0 && node->show_sign && !un_sign)
		sign = '+';
	else if (num == -2147483648 && !un_sign)
	{
		node->show_sign = 0;
		num = ((num + 1) * -1) + 1;
	}
	else if (num < 0 && !un_sign)
	{
		node->show_sign = 1;
		num = -num;
		sign = '-';
	}
	if (!un_sign)
		node->result = ft_itoa(num);
	else
		node->result = ft_uitoa((unsigned int)num);
	check_combination(node);
	convert_modifiers(node, sign);
	ft_putstring(node, node->result);
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
	ft_putstring(node, node->result);
}

void	ft_putpointer(t_printf *node, void *ptr)
{
	unsigned long long	temp;

	temp = (unsigned long long)ptr;
	if (!ptr)
	{
		node->result = ft_strdup(node->nil_error);
		ft_putstring(node, node->result);
		return ;
	}
	node->prefixes = 1;
	ft_puthex(node, node->hex_low, temp, 1);
}
