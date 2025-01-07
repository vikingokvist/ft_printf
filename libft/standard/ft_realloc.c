/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:29:04 by ctommasi          #+#    #+#             */
/*   Updated: 2024/12/03 16:29:05 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_realloc(void *ptr, size_t cur_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (cur_size > 0 && cur_size < new_size)
		ft_memcpy(new_ptr, ptr, cur_size);
	else if (cur_size > 0)
		ft_memcpy(new_ptr, ptr, new_size);
	if (ptr)
		free(ptr);
	return (new_ptr);
}
