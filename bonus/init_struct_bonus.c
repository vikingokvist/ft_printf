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
    node->sign = 0;
    node->width = 0;
	node->dot_precision = 0;
    node->left_justify = 0;
    node->zero_padding = 0;
    node->modifier = 0;
    node->result = NULL;
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

int     is_modifier(char mod)
{
    return (mod == 'c'
        || mod == 's'
        || mod == 'p'
        || mod == 'd'
        || mod == 'u'
        || mod == 'i'
        || mod == 'i'
        || mod == 'x'
        || mod == 'X'
        || mod == '%');
}

