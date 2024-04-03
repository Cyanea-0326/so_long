/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:30:16 by shonakam          #+#    #+#             */
/*   Updated: 2024/04/04 04:54:16 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msgs(int n, t_data *data)
{
	if (n == -1)
		perror("Error\nOpening file");
	else if (n == -2)
		perror("Error\nInvalid map, [not rectangle] or [only linebreak]");
	else if (n == -3)
		perror("Failed malloc.");
	else if (n == -4)
		perror("Error\nFound invalid field");
	else if (n == -5)
		perror("Error\nMap size is invalid.[size<3x5]");
	free_data(data, 0);
	exit(EXIT_FAILURE);
}

void	check_perimeter(t_data *d)
{
	size_t	i;

	i = 0;
	while (1)
	{
		while (i < d->w || ((d->h - 1) * d->w) <= i)
		{
			if (d->map[i].field != '1')
				err_msgs(-4, d);
			i++;
			if (i == (d->h * d->w) -1)
				return ;
		}
		if (d->map[i].field != '1' || d->map[i + d->moves[2] - 1].field != '1')
			err_msgs(-4, d);
		i += d->moves[2];
	}
}

void	check_state(t_data *d)
{
	if (d->state.p_flag != 1 || d->state.g_flag != 1)
		err_msgs(-4, d);
	if (d->state.c_flag < 1)
		err_msgs(-4, d);
}


