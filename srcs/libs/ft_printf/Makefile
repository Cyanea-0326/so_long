CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/*.o

FILES =		format_char.c \
			format_string.c \
			ft_switch_spec.c \
			putnbr_base.c \
			root_putnbr.c \
			ft_printf.c \

OBJ = $(FILES:.c=.o)

all: libftprintf.a

libftprintf.a: $(OBJ)
	make -C ./libft
	ar rcs libftprintf.a $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)
	make -C ./libft clean

fclean:
	make clean
	rm -f libftprintf.a
	make -C ./libft fclean

re: 
	make fclean
	make all
