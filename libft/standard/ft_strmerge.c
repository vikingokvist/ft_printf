/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:23:27 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/22 12:54:18 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmerge(char *start_str, char *end_str)
{
	size_t	i;
	size_t	start_str_len;
	size_t	end_str_len;
	char	*res;

	start_str_len = ft_strlen(start_str);
	end_str_len = ft_strlen(end_str);
	res = malloc(start_str_len + end_str_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start_str[i] && i < start_str_len)
	{
		res[i] = start_str[i];
		i++;
	}
	while (end_str[i - start_str_len] && i < (start_str_len + end_str_len))
	{
		res[i] = end_str[i - start_str_len];
		i++;
	}
	res[i] = '\0';
	return (free(start_str), free(end_str), res);
}
