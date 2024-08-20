/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:46:57 by shonakam          #+#    #+#             */
/*   Updated: 2024/08/20 20:37:01 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "../srcs/libs/minilibx-linux/mlx.h"
# include "/opt/X11/include/X11/X.h"
# include "libs/ft_printf/ft_printf.h"
# include "libs/gnl/get_next_line_bonus.h"

# define MATERIAL_SIZE 32
# define DISPLAY_X 1440
# define DISPLAY_Y 900
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct	s_state {
	int			c_flag;
	int			g_flag;
	int			p_flag;
	size_t		move_counter;
}				t_state;

typedef struct	s_map {
	size_t	row;
	size_t	col;
	char	field;
	int		texture;
}				t_map;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*textures[5];
	char	*path_ber;
	size_t	w;
	size_t	h;
	int		moves[4];
	t_state state;
	char	prev;
	t_map	*map;
}				t_data;

typedef struct	s_validator {
	int			collectbles;
	int			goal;
	size_t		*mark;
	size_t		now;
}				t_validator;

// 
void	load_textures(t_data *data);
void	set_textures(t_data *data);
void	replace_textures(int kc, t_data *data);
void	load_map(t_data *data);

int		sl_controller(int keycode, t_data *data);

void	validate_map(t_data *data);
void	validate_window(t_data *data);

// error
void	err_msgs(int n, t_data *data);
void	check_perimeter(t_data *d);
void	check_state(t_data *d);

// support
size_t	resolve_line_breaks(char *s);
size_t	current_locate(t_data *data);

// close
void	free_data(t_data *data, size_t indexer);
int		on_destroy(t_data *data);
int		observe_esc(int keycode, t_data *data);

void	print_map(t_data *d);

#endif