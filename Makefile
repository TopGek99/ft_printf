NAME = libftprintf.a

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c ft_printcsdi.c ft_printxp.c ft_printu.c

OBJS = $(SRCS:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) all -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRCS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	cd libft && make fclean && cd ..

re: clean all

.PHONY: all clean fclean re
