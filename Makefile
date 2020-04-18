SRCS = 	\
		flags.c \
		float.c \
		ft_itoa_base.c \
		ft_ltoa_base.c \
		ft_printf.c \
		hadle_number.c \
		handle_chars.c \
		modificators.c \
		parse.c \
		pointer.c

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra

OBJECTSFOLD = ./objs
SRCSFOLD = ./src
OBJECTFILES = $(SRCS:.c=.o)
OBJECTS = $(patsubst %.o, $(OBJECTSFOLD)/%.o, $(OBJECTFILES))

all: $(NAME)

$(NAME): $(OBJECTSFOLD) $(OBJECTS)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTSFOLD)/%.o: $(SRCSFOLD)/%.c
	gcc -c $^ -Iinc/ -o $@

$(OBJECTSFOLD):
	mkdir $(OBJECTSFOLD)

clean:
	rm -rf $(OBJECTSFOLD)

fclean: clean
	rm -f $(NAME)

re: fclean all
