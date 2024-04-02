/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:25:34 by shonakam          #+#    #+#             */
/*   Updated: 2024/04/02 23:03:10 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	current_locate(t_data *data)
{
	size_t	current;

	current = 0;
	while (data->map[current].field != 'P')
		current++;
	return (current);
}

static char	verify_dest(int kc, t_data *data)
{
	if (kc == KEY_W)
	{
		return (data->map[current_locate(data) - data->w].field);
	}
	else if (kc == KEY_A)
	{
		return (data->map[current_locate(data) - 1].field);
	}
	else if (kc == KEY_S)
	{
		return (data->map[current_locate(data) + data->w].field);
	}
	else if (kc == KEY_D)
	{
		return (data->map[current_locate(data) + 1].field);
	}
	return (-1);
}

void	move_charctor(int kc, t_data *data)
{
	if (verify_dest(kc, data) == '0')
	{
		replace_textures(kc, data);
		data->state.move_counter++;
		ft_printf("Moved: [%u]\n", data->state.move_counter);
	}
	else if (verify_dest(kc, data) == 'C')
	{
		replace_textures(kc, data);
		data->state.c_flag--;
		data->state.move_counter++;
		ft_printf("Remaining collectibles: [%d]\n", data->state.c_flag);
		ft_printf("Moved: [%u]\n", data->state.move_counter);
	}
	else if (verify_dest(kc, data) == 'E')
	{
		if (data->state.c_flag > 0)
			return ((void)ft_printf("Collectibles are lef.\n"));
		ft_printf("\n---- GAME CLEAR ----\n");
		ft_printf("Total moved: %d\n\n",data->state.move_counter);
		on_destroy(data);
	}
}

int	sl_controller(int kc, t_data *data)
{
	(void)data;
	if (kc == KEY_W || kc == KEY_A || kc == KEY_S || kc == KEY_D)
	{
		move_charctor(kc, data);
	}
	return (0);
}