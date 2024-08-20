CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/*.o

FILES =		format_char.c \
			format_string.c \
			ft_switch_spec.c \
			putnbr_base.c \
			root_putnbr.c \
			ft_printf.c \

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

all: libftprintf.a

libftprintf.a: $(OBJ)
	@make -C ./libft
	@ar rcs libftprintf.a $(FILES:.c=.o) $(LIBFT)

clean:
	@rm -f $(OBJ)
	@make -C ./libft clean

fclean: clean
	@rm -f libftprintf.a
	@make -C ./libft fclean

re: fclean all
