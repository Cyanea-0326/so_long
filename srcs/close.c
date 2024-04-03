/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:48:05 by shonakam          #+#    #+#             */
/*   Updated: 2024/04/03 12:49:39 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < 5)
		free(data->textures[i++]);
	if (data->map)
		free(data->map);
	free(data->mlx);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_data(data);
	exit(0);
}

int	observe_esc(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		on_destroy(data);
	return (0);
}
