/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 05:22:45 by shonakam          #+#    #+#             */
/*   Updated: 2024/04/03 10:01:28 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memo
// 1:マップの高さと幅を記録
// 2:高さ*幅+1の配列を作成

// :外周が1か確認
// :C,E,Pの個数をflagで管理どれかが2になった瞬間error
// :ルートの確認

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
		else if (c == 'P' && data->playerflag++ > 0)
			return (1);
		return (0);
	}
	return (1);
}

size_t	resolve_line_breaks(char *s)
{
	if (ft_strchr(s, '\n'))
	{
		return (ft_strlen(s) - 1);
	}
	return (ft_strlen(s));
}

static char	*set_firstline(t_data *data, int fd, char *line)
{
	line = get_next_line(fd);
	while (ft_strlen(line) - 1 == 0)
	{
		line = get_next_line(fd);
	}
	data->w = resolve_line_breaks(line);
	return (line);
}

void	set_elements(t_data *data, char *line, size_t row)
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
		{
			perror("Found invalid field");
			exit(EXIT_FAILURE);
		}
		data->map[current].field = *line;
		data->map[current].row = row;
		data->map[current].col = col++;
		data->map[current].end = 0;
		current++;
		line++;
	}
}

void	set_map(t_data *data, int fd)
{
	t_map	*map;
	char	*line;
	size_t	index;

	map = (t_map *)malloc(sizeof(t_map)
			* (data->w * data->h + 1));
	if (!map)
		exit (EXIT_FAILURE);
	data->map = map;
	fd = open(data->path_ber, O_RDONLY);
	line = NULL;
	line = set_firstline(data, fd, line);
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
	data->map[(data->w * data->h)].end = 1;
}

void	load_map(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->path_ber, O_RDONLY);
	line = NULL;
	line = set_firstline(data, fd, line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL && resolve_line_breaks(line) != data->w)
		{
			perror("map is invalid");
			free(line);
			exit(EXIT_FAILURE);
		}
		data->h++;
	}
	free(line);
	close(fd);
	set_map(data, fd);
}
