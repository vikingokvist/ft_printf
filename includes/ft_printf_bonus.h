/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:31:56 by ctommasi          #+#    #+#             */
/*   Updated: 2025/01/07 14:31:58 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h> //REMOVE AFTER
# include "../libft/includes/libft.h"

typedef struct s_printf
{
	char	*full_str;
	char	*result;
	char	*null_error;
	char	*nil_error;
	char	*hex_up;
	char	*hex_low;
	char	modifier;
	int		len;
	int		left_justify;
	int		zero_padding;
	int		dot_precision;
	int		width;
	int		show_sign;
	int		prefixes;
	int		space;
	int		has_flag;
}	t_printf;

t_printf	*init_struct(t_printf *node);
//--------------------------------------------------------------MAIN/BONUS
int			ft_printf(const char *format, ...);
char		*parse_modifiers(t_printf *node, char *str);
char		*assign_padding(t_printf *node, char *str, int *padding);
void		call_modifiers(t_printf *node, va_list args);
//--------------------------------------------------------------FUNCTIONS
void		ft_putchars(t_printf *node, char c);
void		ft_putstring(t_printf *node, char *str);
void		ft_putnumber(t_printf *node, int num, int un_sign);
void		ft_puthex(t_printf *node, char *hex, unsigned long nb, char prefix);
void		ft_putpointer(t_printf *node, void *ptr);
//--------------------------------------------------------------INIT_STRUCT
void		init_node(t_printf *node);
void		free_node(t_printf *node);
//--------------------------------------------------------------CONVERSIONS
void		convert_modifiers(t_printf *node, char sign);
void		fill_padding(t_printf *node, char *new_num, char c, int padding);
char		*add_padding(t_printf *node, int *padding_type, char c);
char		*add_sign(t_printf *node, char sign, int add_extra, int len);
char		*add_prefix(t_printf *node, char sign);
//--------------------------------------------------------------UTILS_BONUS
int			is_modifier(char mod);
int			has_flag(t_printf *node);
int			ft_is_hex_or_num(int c);
void		check_combination(t_printf *node);

#endif