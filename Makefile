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
CFLAGS = -Wall -Wextra -Werror -I ./include -I ./libft/includes
RM = rm -f
AR = ar crs

SRCS = ./standard/ft_printf.c ./standard/ft_printf_utils.c \
	./bonus/ft_printf_bonus.c ./bonus/init_struct_bonus.c \
	./bonus/utils_bonus.c ./bonus/functions_bonus.c \
	./bonus/conversions_bonus.c

#BONUS = 

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(AR) $(NAME) $(LIBFT) $(OBJS) 

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
