/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:03:30 by ctommasi          #+#    #+#             */
/*   Updated: 2024/09/19 18:03:32 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free(char *total_chars, char *temp)
{
	char	*res;
	size_t	i;
	size_t	total_len;
	size_t	temp_len;

	if (!total_chars || !temp)
		return (NULL);
	total_len = ft_strlen(total_chars);
	temp_len = ft_strlen(temp);
	res = malloc(total_len + temp_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < total_len)
	{
		res[i] = total_chars[i];
		i++;
	}
	while (i < total_len + temp_len)
	{
		res[i] = temp[i - total_len];
		i++;
	}
	res[i] = '\0';
	return (free(total_chars), res);
}
