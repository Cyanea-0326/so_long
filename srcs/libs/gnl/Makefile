CFLAGS = -Wall -Werror -Wextra -I./get_next_line_bonus.h
FILES = get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJS = $(FILES:.c=.o)

all: gnl.a

gnl.a:
	gcc $(CFLAGS) -c $(FILES)
	ar rcs gnl.a $(FILES:.c=.o)

clean:
	rm -f $(GNL) $(OBJS)

fclean: clean
	rm -f gnl.a

re: fclean all

.SILENT:
