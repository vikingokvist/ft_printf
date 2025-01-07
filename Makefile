# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 11:23:10 by ctommasi          #+#    #+#              #
#    Updated: 2024/10/01 11:23:16 by ctommasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./includes -I ./libft/includes
RM = rm -f
AR = ar crs

SRCS = ./standard/ft_printf.c ./standard/ft_printf_utils.c \
	
BONUS = ./bonus/ft_printf_bonus.c ./bonus/init_struct_bonus.c ./bonus/utils_bonus.c \
	./bonus/functions_bonus.c ./bonus/conversions_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(BONUS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

bonus: fclean $(LIBFT) $(OBJS_B) 
	@$(AR) $(NAME) $(OBJS_B) $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@$(RM) $(OBJS) $(OBJS_B)
	@$(MAKE) clean -C $(LIBFT_DIR)
	
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
