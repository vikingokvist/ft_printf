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
# include <stdio.h> //REMOVE AFTER

typedef struct s_printf
{
    char    *full_str;
    char    *result;
    char    *null_error;
    char    *nil_error;
    char    *hex_up;
    char    *hex_low;
    char    modifier;
    int     len;
    int     left_justify;
    int     zero_padding;
    int     dot_precision;
    int     width;
    int     show_sign;
    int     prefixes;
    int     space;
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
char	*parse_modifiers(t_printf *node, char *str);
char	*assign_padding(t_printf *node, char *str, int *padding);
void	call_modifiers(t_printf *node, va_list args);
//--------------------------------------------------------------INIT_STRUCT
t_printf	*init_struct(t_printf *node);
void	init_node(t_printf *node);
void	free_node(t_printf *node);
//--------------------------------------------------------------FUNCTIONS
void	ft_putchars(t_printf *node, char c);
void	ft_putstring(t_printf *node, char *str);
void    ft_putnumber(t_printf *node, int num, int un_sign);
void	ft_puthex(t_printf *node, char *hex, unsigned long nb, char prefix);
void	ft_putpointer(t_printf *node, void *ptr);
//--------------------------------------------------------------CONVERSIONS
void	convert_modifiers(t_printf *node, char sign);
void    fill_padding(t_printf *node, char *new_num, char c, int padding);
char	*add_padding(t_printf *node, int *padding_type, char c);
char    *add_sign(t_printf *node, char sign, int add_extra, int len);
char    *add_prefix(t_printf *node, char sign);
//--------------------------------------------------------------FUNCTIONS_UTILS
char	*ft_itoa(int n);
char    *ft_uitoa(unsigned int n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_realloc(void *ptr, size_t cur_size, size_t new_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
//--------------------------------------------------------------UTILS_BONUS
int is_modifier(char mod);
int	ft_is_hex_or_num(int c);
void    check_combination(t_printf *node);

#endif
