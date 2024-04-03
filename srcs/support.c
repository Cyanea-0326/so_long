/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:09:25 by shonakam          #+#    #+#             */
/*   Updated: 2024/04/04 03:09:06 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	resolve_line_breaks(char *s)
{
	if (ft_strchr(s, '\n'))
	{
		return (ft_strlen(s) - 1);
	}
	return (ft_strlen(s));
}

size_t	current_locate(t_data *data)
{
	size_t	current;

	current = 0;
	while (data->map[current].field != 'P')
		current++;
	return (current);
}

void	print_map(t_data *d)
{
	for (size_t i=0; i<d->h*d->w; i++) {
		printf("%c", d->map[i].field);
		if ((i + 1) % d->w == 0) {
			printf("\n");
		}
	}
}
