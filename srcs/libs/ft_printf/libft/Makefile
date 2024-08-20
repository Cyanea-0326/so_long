# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:35:50 by shonakam          #+#    #+#              #
#    Updated: 2024/04/04 09:02:44 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -I./includes -Wall -Wextra -Werror

FILES =		ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

all: libft.a

libft.a: $(FILES:%.c=%.o)
	@ar rcs libft.a $(FILES:%.c=%.o)

clean:
	@rm -f $(FILES:%.c=%.o)

fclean: clean
	@rm -f libft.a

re: fclean all

.SILENT:
