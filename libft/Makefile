NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar crs

SRCS_STANDARD = standard/ft_atoi.c standard/ft_isalnum.c standard/ft_isalpha.c standard/ft_isascii.c \
	standard/ft_isdigit.c standard/ft_isprint.c standard/ft_memcpy.c standard/ft_memmove.c \
	standard/ft_memset.c standard/ft_strchr.c standard/ft_strlcat.c standard/ft_strlcpy.c \
	standard/ft_strlen.c standard/ft_strncmp.c standard/ft_strnstr.c standard/ft_strrchr.c \
	standard/ft_tolower.c standard/ft_toupper.c standard/ft_memchr.c standard/ft_memcmp.c \
	standard/ft_calloc.c standard/ft_bzero.c standard/ft_strdup.c standard/ft_substr.c \
	standard/ft_strjoin.c standard/ft_strtrim.c standard/ft_split.c standard/ft_itoa.c \
	standard/ft_strmapi.c standard/ft_striteri.c standard/ft_putchar_fd.c standard/ft_putstr_fd.c \
	standard/ft_putendl_fd.c standard/ft_putnbr_fd.c standard/ft_strcmp.c standard/ft_sqrt.c \
	standard/ft_strstr.c standard/ft_strdelchar.c standard/ft_realloc.c standard/ft_ptrdelchar.c \
	standard/ft_strmerge.c standard/ft_printf.c standard/ft_printf_utils.c standard/get_next_line.c \
	standard/ft_lstnew.c standard/ft_lstadd_front.c standard/ft_lstsize.c standard/ft_lstlast.c \
	standard/ft_lstadd_back.c standard/ft_lstdelone.c standard/ft_lstclear.c standard/ft_lstiter.c \
	standard/ft_lstmap.c standard/ft_lstfree.c standard/ft_lstinit_index.c standard/ft_lstlast.c \
	standard/ft_lstlen.c standard/ft_lstmax_index.c standard/ft_lst_isordered.c standard/ft_lstcheck_dupe.c \
	standard/ft_strjoin_free.c standard/ft_uitoa.c

OBJS_STANDARD = $(SRCS_STANDARD:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_STANDARD)
	@$(AR) $(NAME) $(OBJS_STANDARD)

standard: $(OBJS_STANDARD)
	@$(AR) $(NAME) $(OBJS_STANDARD)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_STANDARD)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re standard