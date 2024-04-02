/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:40:35 by shonakam          #+#    #+#             */
/*   Updated: 2024/04/02 21:43:52 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	observe_esc(int keycode, t_data *data)
{
	(void)data;
	if (keycode == KEY_ESC)
		on_destroy(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	// .ber飲みにしたい
	data.path_ber = av[1];

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	load_textures(&data);
	load_map(&data);
	data.win = mlx_new_window(data.mlx, 
		(data.w * MATERIAL_SIZE), ((data.h + 1) * MATERIAL_SIZE), "./so_long");
	if (!data.win)
		return (free(data.win), 1);
	set_textures(&data);
	mlx_key_hook(data.win, observe_esc, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, on_destroy, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, sl_controller, &data);
	mlx_loop(data.mlx);
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q so_long");
}