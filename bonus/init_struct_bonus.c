#include "ft_printf.h"

t_printf	*init_struct(t_printf *node)
{
	node = (t_printf *)malloc(sizeof(t_printf));
	if (!node)
		return (NULL);
	init_node(node);
	node->null_error = ft_strdup("(null)");
	node->nil_error = ft_strdup("(nil)");
	node->len = 0;
	node->full_str = ft_strdup("");
	return (node);
}

void	init_node(t_printf *node)
{
    node->prefixes = false;
    node->space = false;
    node->show_sign = 0;
    node->width = 0;
	node->dot_precision = 0;
    node->left_justify = 0;
    node->zero_padding = 0;
    node->modifier = 0;
    node->result = NULL;
}

char	*assign_padding(t_printf *node, char *str)
{
	int		padding;

	padding = 0;
	if (node->width != -1)
		str++;
	if (*str && *str >= '1' && *str <= '9')
	{
		while (*str >= '0' && *str <= '9')
		{
			padding = (padding * 10) + (*str - '0');
			str++;
		}
	}
	else
		padding = -1;
	if (node->left_justify == -1)
		node->left_justify = padding;
	else if (node->dot_precision == -1)
		node->dot_precision = padding;
	else if (node->zero_padding == -1)
		node->zero_padding = padding;
	else if (node->width == -1)
		node->width = padding;
	str--;
	return (str);
}

void	free_node(t_printf *node)
{
	if (node->full_str)
		free(node->full_str);
	if (node->result)
		free(node->result);
    // if (node->nil_error)
    //     free(node->nil_error);
    // if (node->null_error)
    //     free(node->null_error);
	free(node);
}
