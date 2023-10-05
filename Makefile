SRCS		=	$(wildcard *.c)


OBJS		=	$(SRCS:.c=.o)

NAME		=	push_swap

CFLAGS		=	-Wall -Wextra -Werror 

LIB_FLAGS	=	-L . -l $(LIBFT)

LIBFT		=ft
LIBFT_DIR = libft

all			:	$(NAME)

clean		:
				$(MAKE) -C $(LIBFT_DIR) clean
				$(RM) $(OBJS)

fclean		:	clean
				$(MAKE) -C $(LIBFT_DIR) fclean
				$(RM) $(NAME)

re			:
				$(MAKE) fclean
				$(MAKE)	all

$(NAME)		:	$(OBJS)
				$(MAKE) -C $(LIBFT_DIR)
				$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(LIBFT) $^ -o $@

bonus		:	$(NAME)

.PHONY		:	all clean fclean re bonus