
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

void	ft_putnumber(t_printf *node, int num)
{
	char	*number;
	int		num_len;
	int		i;
	int		j;
	int		sign;

	sign = 0;
	if (num < 0)
		sign = 1;
	if (sign)
		num = -num;
	number = ft_itoa(num);
	num_len = ft_strlen(number);
	i = 0;
	while (i < node->zero_padding - num_len)
	{
		ft_putchars(node, '0');
		i++;
	}
	if (sign)
		ft_putchars(node, '-');
	else if (node->sign)
		ft_putchars(node, '+');
	else if (node->space)
		ft_putchars(node, ' ');

	// Print the actual number
	j = 0;
	while (number[j])
	{
		ft_putchars(node, number[j]);
		j++;
	}
}


// int	ft_putnbr_hex(unsigned long long nb, int up_or_low)
// {
// 	int		len;
// 	char	hex_low;
// 	char	hex_up;

// 	len = 0;
// 	hex_low = "0123456789abcdef"[nb % 16];
// 	hex_up = "0123456789ABCDEF"[nb % 16];
// 	if (nb >= 16)
// 		len += ft_putnbr_hex(nb / 16, up_or_low);
// 	if (up_or_low == 0)
// 		len += ft_putchar(hex_low);
// 	else
// 		len += ft_putchar(hex_up);
// 	return (len);
// }



// int	ft_putptr(void *ptr)
// {
// 	int					len;
// 	unsigned long long	temp;

// 	temp = (unsigned long long)ptr;
// 	len = 0;
// 	if (!ptr)
// 	{
// 		write(1, "(nil)", 5);
// 		return (5);
// 	}
// 	len += ft_putstr("0x");
// 	len += ft_putnbr_hex(temp, 0);
// 	return (len);
// }
