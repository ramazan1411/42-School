NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = ft_printf.c ft_funcs.c ft_puts.c

OBJS = $(SRCS:.c=.o)
			
all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
		
fclean:	clean
	$(RM) $(NAME)
		
re: fclean all