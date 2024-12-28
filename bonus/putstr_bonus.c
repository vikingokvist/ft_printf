
#include "ft_printf.h"

void	ft_putchars(t_printf *node, char c)
{
	int		len;

	len = ft_strlen(node->full_str);
	node->full_str = ft_realloc(node->full_str, len + 1, len + 2);
	node->full_str[len] = c;
	node->full_str[len + 1] = '\0';
}

void	ft_putstring(t_printf *node, char *str)
{
	if (str == NULL)
		str = node->null_error;
	while (*str != '\0')
	{
		ft_putchars(node, *str);
		str++;
	}
}
