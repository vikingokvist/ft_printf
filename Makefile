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
CFLAGS = -Wall -Wextra -Werror -I ./include
RM = rm -f
AR = ar crs

SRCS = ./standard/ft_printf.c ./standard/ft_printf_utils.c \
	./bonus/ft_printf_bonus.c ./bonus/init_struct_bonus.c ./bonus/utils_bonus.c \
	./bonus/utils_bonus2.c ./bonus/convert_mod_bonus.c

# BONUS = 

OBJS = $(SRCS:.c=.o)
# OBJS_B = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

# bonus: $(OBJS_B)
# 	$(AR) $(OBJS_B) -o $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
