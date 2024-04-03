/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:46:10 by shonakam          #+#    #+#             */
/*   Updated: 2024/04/03 12:30:49 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_data *data)
{
	int	width;
	int	height;

	width = MATERIAL_SIZE;
	height = MATERIAL_SIZE;
	data->textures[0] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/textures/0_charctor.xpm", &width, &height);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/textures/1_goal.xpm", &width, &height);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/textures/2_item.xpm", &width, &height);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/textures/3_wall.xpm", &width, &height);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/textures/4_floor.xpm", &width, &height);
}

static void	update_texture(int index, int selector, t_data *data)
{
	data->map[index].texture
		= mlx_put_image_to_window(data->mlx, data->win,
			data->textures[selector],
			((data->map[index].col) * MATERIAL_SIZE),
			((data->map[index].row) * MATERIAL_SIZE));
}

static int	get_texture_id(char c)
{
	if (c == 'P')
		return (0);
	else if (c == 'E')
		return (1);
	else if (c == 'C')
		return (2);
	else if (c == '1')
		return (3);
	else if (c == '0')
		return (4);
	return (0);
}

void	set_textures(t_data *data)
{
	size_t	index;
	int		selector;

	index = 0;
	while (index < (data->h * data->w))
	{
		selector = get_texture_id(data->map[index].field);
		update_texture(index, selector, data);
		index++;
	}
}

void	replace_textures(int kc, t_data *data)
{
	size_t	i;

	i = current_locate(data);
	if (data->prev == 'C')
		data->prev = '0';
	data->map[i].field = data->prev;
	update_texture(i, get_texture_id(data->map[i].field), data);
	if (kc == KEY_W)
		i -= data->w;
	else if (kc == KEY_A)
		i -= 1;
	else if (kc == KEY_S)
		i += data->w;
	else if (kc == KEY_D)
		i += 1;
	data->prev = data->map[i].field;
	data->map[i].field = 'P';
	update_texture(i, 0, data);
}
