SO_LONG = so_long

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g $(INCLUDES) -I$(PATH)so_long.h $(FT_PRINTF_A) $(LIBFT_A) $(GNL_A) $(MLX_A)
# CFLAGS = -Wall -Werror -Wextra $(INCLUDES) -I$(PATH)so_long.h $(FT_PRINTF_A) $(LIBFT_A) $(GNL_A) $(MLX_A)
INCLUDES = -I/opt/X11/include -I./srcs/libs/mlx

SRC_PATH = ./srcs/

FILES = $(SRC_PATH)main.c \
		$(SRC_PATH)close.c \
		$(SRC_PATH)error.c \
		$(SRC_PATH)graphic.c \
		$(SRC_PATH)readmap.c \
		$(SRC_PATH)controll.c \
		$(SRC_PATH)validate.c \
		$(SRC_PATH)support.c \

MLX_FLAG = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
X11_FLAGS = -L/usr/X11/lib -lXext -lX11

FT_PRINTF_A = $(SRC_PATH)libs/ft_printf/libftprintf.a
LIBFT_A = $(SRC_PATH)libs/ft_printf/libft/libft.a
GNL_A = $(SRC_PATH)libs/gnl/gnl.a
MLX_A = $(SRC_PATH)libs/minilibx-linux/libmlx_Darwin.a

all: $(SO_LONG)

$(SO_LONG):
	@make -C $(SRC_PATH)libs/ft_printf/libft
	@make -C $(SRC_PATH)libs/ft_printf
	@make -C $(SRC_PATH)libs/gnl
	@gcc $(CFLAGS) $(FILES) -o $(SO_LONG) $(MLX_FLAGS) $(X11_FLAGS)
	@echo "so_long-Success!!"

run: re
	./$(SO_LONG) ./so_long_invalidator/maps/invalid/no_coins_path.ber

clean:
	make -C $(SRC_PATH)libs/ft_printf clean
	make -C $(SRC_PATH)libs/gnl clean

fclean: clean
	rm -f $(SO_LONG)
	make -C $(SRC_PATH)libs/ft_printf fclean
	make -C $(SRC_PATH)libs/gnl fclean

re: fclean all

.PHONY: all clean fclean re run
