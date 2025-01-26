NAME = libftprintf.a
SRCS = ft_printf.c ft_ptrptr.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putunsigned.c ft_putstr.c
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re