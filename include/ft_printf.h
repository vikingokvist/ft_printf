/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:23:13 by ctommasi          #+#    #+#             */
/*   Updated: 2024/09/30 12:23:16 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum s_bool
{
    true = 1,
    false = 0
}   t_bool;

typedef struct s_printf
{
    char    *full_str;
    char    *result;
    char    *null_error;
    char    *nil_error;
    char    modifier;
    int     len;
    int     left_justify;
    int     zero_padding;
    int     dot_precision;
    int     width;
    int     sign;
    t_bool     prefixes;
    t_bool     space;
}   t_printf;

//--------------------------------------------------------------MAIN
int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_dec(long nb);
int	ft_putnbr_hex(unsigned long long nb, int up_or_low);
int	ft_putptr(void *ptr);
//--------------------------------------------------------------BONUS_MAIN
int	ft_printfb(const char *format, ...);
char	*get_padding(t_printf *node, char *str);
void	convert_modifiers(t_printf *node, va_list args);
//--------------------------------------------------------------BONUS_TRANSFORM
void	ft_putchars(t_printf *node, char c);
void	ft_putstring(t_printf *node, char *str);
void	ft_putnumber(t_printf *node, int num);
char	*add_padding(t_printf *node, char *number, int padding_type, char c);
void    fill_padding_right(char *new_num, char *number, char c, int padding);
void    fill_padding_left(char *new_num, char *number, char c, int padding);
char    *add_sign(char *number, char sign, int add_extra);
//--------------------------------------------------------------INIT_STRUCT
t_printf	*init_struct(t_printf *node);
void	init_node(t_printf *node);
char	*init_modifiers(t_printf *node, char *str);
void	free_node(t_printf *node);
int is_modifier(char mod);
//--------------------------------------------------------------UTILS_BONUS2
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_realloc(void *ptr, size_t cur_size, size_t new_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putchars(t_printf *node, char c);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

#endif
