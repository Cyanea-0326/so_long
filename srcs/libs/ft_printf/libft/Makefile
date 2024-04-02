# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:35:50 by shonakam          #+#    #+#              #
#    Updated: 2023/10/12 17:57:03 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -I./includes -Wall -Wextra -Werror

FILES =		ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_strchr \
			ft_strlen \
			ft_strlcpy \
			ft_strlcat \
			ft_strrchr \
			ft_strnstr \
			ft_strncmp \
			ft_toupper \
			ft_tolower \
			ft_strdup \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_itoa \
			ft_strmapi \
			ft_striteri \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \

all: libft.a

libft.a: $(FILES:%=%.o)
	ar rcs libft.a $(FILES:%=%.o)

clean:
	rm -f $(FILES:%=%.o)

fclean:
	make clean
	rm -f libft.a

re: 
	make fclean
	make all
