SRCS		=	$(wildcard *.c)


OBJS		=	$(SRCS:.c=.o)

NAME		=	push_swap

CFLAGS		=	-Wall -Wextra -Werror 

LIB_FLAGS	=	-L. -l $(LIBFT)

LIBFT		=	ft

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:
				$(MAKE) fclean
				$(MAKE)	all

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(LIB_FLAGS)  $^ -o $@

bonus		:	$(NAME)

.PHONY		:	all clean fclean re bonus