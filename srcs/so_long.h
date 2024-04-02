/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:46:57 by shonakam          #+#    #+#             */
/*   Updated: 2024/04/02 22:51:31 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../srcs/libs/minilibx-linux/mlx.h"
# include "/opt/X11/include/X11/X.h"
# include "libs/ft_printf/ft_printf.h"
# include "libs/gnl/get_next_line_bonus.h"

# define MATERIAL_SIZE 32
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct	s_state {
	int			c_flag;
	int			g_flag;
	size_t		move_counter;
}				t_state;

typedef struct	s_map {
	size_t	row;
	size_t	col;
	char	field;
	int		texture;
	int		end;
}				t_map;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*textures[6];
	char	*path_ber;
	int		playerflag;
	size_t	w;
	size_t	h;
	t_state state;
	t_map	*map;
}				t_data;

void	load_textures(t_data *data);
void	set_textures(t_data *data);
void	replace_textures(int kc, t_data *data);
void	load_map(t_data *data);

int		current_locate(t_data *data);
int		sl_controller(int keycode, t_data *data);

void	draw_text(void *mlx, void *win, int x, int y, char *text);
int on_destroy(t_data *data);

#endif