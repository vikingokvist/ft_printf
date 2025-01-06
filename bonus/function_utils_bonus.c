#include "ft_printf.h"

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_temp;
	const unsigned char	*src_temp;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	dest_temp = (unsigned char *)dest;
	src_temp = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_temp[i] = src_temp[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*temp;
	size_t	i;

	temp = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

static int	ft_int_len(int n)
{
	int	count;

	count = 0;
	if (n != 0)
	{
		if (n < 0)
		{
			n = n *(-1);
			count++;
		}
		while (n != 0)
		{
			n = n / 10;
			count++;
		}
	}
	else
		count = 1;
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*res;
	long int	nbr;

	len = ft_int_len(n);
	nbr = n;
	res = malloc((len + 1));
	if (!res)
		return (NULL);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		res[0] = '0';
	res[len--] = '\0';
	while (nbr)
	{
		res[len] = ((nbr % 10) + '0');
		nbr /= 10;
		len--;
	}
	return (res);
}
