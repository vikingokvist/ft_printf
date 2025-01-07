/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:23:44 by ctommasi          #+#    #+#             */
/*   Updated: 2024/10/29 18:23:56 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_sqrt(int nb)
{
	int	left;
	int	right;
	int	mid;
	int	result;

	if (nb <= 0)
		return (0);
	left = 1;
	right = nb;
	result = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (mid < nb / mid)
		{
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return (result);
}
