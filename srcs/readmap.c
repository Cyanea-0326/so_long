/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 05:22:45 by shonakam          #+#    #+#             */
/*   Updated: 2024/04/04 03:21:18 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memo
// 1:マップの高さと幅を記録
// 2:高さ*幅+1の配列を作成

// :外周が1か確認
// :ルートの確認

// Map with an Empty Line. [empty-line]
#include "so_long.h"

// validate [C,E,P] If there are two or more.
static int	is_invalidfield(char c, t_data *data)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
	{
		if (c == 'C')
			data->state.c_flag++;
		else if (c == 'E')
			data->state.g_flag++;
		else if (c == 'P')
			data->state.p_flag++;
		return (0);
	}
	return (1);
}

// check: "empty map" or "consists only of linebrake characters"
// check: min value [5 <= w]
static char	*set_firstline(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		free(line);
		err_msgs(-2, data);
	}
	while (line && ft_strlen(line) - 1 == 0)
		line = get_next_line(fd);
	if (!line)
		err_msgs(-2, data);
	data->w = resolve_line_breaks(line);
	return (line);
}

static void	set_elements(t_data *data, char *line, size_t row)
{
	size_t	current;
	size_t	col;
	size_t	count;

	current = (data->w * row);
	col = 0;
	if (!line)
		return ;
	count = resolve_line_breaks(line);
	while (count--)
	{
		if (is_invalidfield(*line, data))
			err_msgs(-4, data);
		data->map[current].field = *line;
		data->map[current].row = row;
		data->map[current].col = col++;
		current++;
		line++;
	}
}

static void	set_map(t_data *data, int fd)
{
	char	*line;
	size_t	index;

	data->map = (t_map *)malloc(sizeof(t_map)
			* (data->w * data->h));
	if (!data->map)
		err_msgs(-3, data);
	fd = open(data->path_ber, O_RDONLY);
	if (fd == -1)
		err_msgs(-1, data);
	line = set_firstline(data, fd);
	set_elements(data, line, 0);
	free(line);
	index = 1;
	while (index < data->h)
	{
		line = get_next_line(fd);
		set_elements(data, line, index++);
		free(line);
	}
	close(fd);
}

void	load_map(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->path_ber, O_RDONLY);
	if (fd == -1)
		err_msgs(-1, data);
	line = set_firstline(data, fd);
	// printf("> %s", line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL && *line != '\n'
			&& resolve_line_breaks(line) != data->w)
		{
			free(line);
			err_msgs(-2, data);
		}
		if (line != NULL && *line != '\n')
			data->h++;
		// printf("> %s", line);
	}
	free(line);
	close(fd);
	set_map(data, fd);
	if (data->h * data->w < 15)
		err_msgs(-5, data);
}
