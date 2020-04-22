# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 20:30:28 by dderevyn          #+#    #+#              #
#    Updated: 2020/04/22 17:10:07 by acyrenna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS_DIR = .objects
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

LIBFT_PATH = libft/
LIBFT_INCS =	libft.h
LIBFT_SRCS = 	ft_isdigit.c\
				ft_memalloc.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_pow.c\
				ft_strchr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strnchr.c\
				ft_strnew.c\
				ft_strrev.c\
				ft_strsub.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memcpy.c\
				ft_get_nb_size.c\
				ft_putstr.c\
				ft_putchar.c
LIBFT_OBJS = $(LIBFT_SRCS:%.c=$(LIBFT_OBJS_DIR)/%.o)
LIBFT_OBJS_DIR = $(OBJS_DIR)

PRINTF_PATH = src/
PRINTF_INCS =	./inc/ft_printf.h
PRINTF_SRCS =	ft_itoa_base.c\
				ft_ltoa_base.c\
				write.c\
				flags.c\
				float.c\
				ft_printf.c\
				handle_chars.c\
				handle_number.c\
				modificators.c\
				parse.c\
				print.c
PRINTF_OBJS = $(PRINTF_SRCS:%.c=$(PRINTF_OBJS_DIR)/%.o)
PRINTF_OBJS_DIR = $(OBJS_DIR)

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

$(LIBFT_OBJS_DIR)/%.o: $(LIBFT_PATH)%.c
	@mkdir -p $(LIBFT_OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(LIBFT_PATH),$(LIBFT_INCS))) -o $@

$(PRINTF_OBJS_DIR)/%.o: $(PRINTF_PATH)%.c
	@mkdir -p $(LIBFT_OBJS_DIR)
	$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(PRINTF_PATH),$(PRINTF_INCS))) -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	@norminette $(addprefix $(LIBFT_PATH),$(LIBFT_SRCS)) \
	$(addprefix $(LIBFT_PATH),$(LIBFT_INCS)) \
	$(addprefix $(PRINTF_PATH),$(PRINTF_SRCS)) \
	$(addprefix $(PRINTF_PATH),$(PRINTF_INCS))

run:
	@$(CC) $(CFLAGS) main.c libftprintf.a | cat -e
	@./a.out || true
	@$(RM) ./a.out

run_warn:
	@$(CC) main.c libftprintf.a
	@./a.out || true
	@$(RM) ./a.out

test: rmt
	@mkdir -p test
	@cp -rf $(LIBFT_PATH) test/$(LIBFT_PATH)
	@cp -rf $(PRINTF_PATH) test/$(PRINTF_PATH)
	@cp -rf author test/author
	@cp -rf Makefile test/Makefile
	@cd test && pwd | cut -c 17-44

rmt:
	@$(RM) test

.PHONY: all clean fclean re norm run run_warn test rmt
