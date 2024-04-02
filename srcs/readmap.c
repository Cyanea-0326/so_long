/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 05:22:45 by shonakam          #+#    #+#             */
/*   Updated: 2024/04/02 22:38:47 by shonakam         ###   ########.fr       */
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
static int		is_invalidfield(char c, t_data *data)
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

void	set_elements(t_data *data, char *line, size_t row)
{
	size_t	current;
	size_t	col;

	current = (data->w * row);
	col = 0;
	if (!line)
		return ;
	while (*line != '\n')
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

	map = (t_map *)malloc(sizeof(t_map) * (data->w * data->h + 1));
	if(!map)
		exit (EXIT_FAILURE);
	data->map = map;
	fd = open(data->path_ber, O_RDONLY);
	index = 0;
	while (index < data->h)
	{
		line = get_next_line(fd);
		set_elements(data, line, index++);
		free(line);
	}
	close(fd);
	data->map[(data->w * data->h)].end = 1;

	// for (size_t i = 0; i < data->h; i++) {
	// 	for (size_t j = 0; j < data->w; j++) {
	// 		printf("%c", data->map[i * data->w + j].field);
	// 	}
	// 	printf("\n");
	// }
	// printf("-------------------------------------\n");
	// size_t j=0;
	// for (size_t i=0; i<(data->h * data->w); i++) {
	// 	printf("%c", data->map[i].field);
	// 	j++;
	// 	if (j == data->w)
	// 	{
	// 		printf("\n");
	// 		j=0;
	// 	}
	// }
}

static void	data_init(t_data *data)
{
	data->w = 0;
	data->h = 0;
	data->playerflag = 0;
	data->state.c_flag = 0;
	data->state.g_flag = 0;
	data->state.move_counter = 0;
	data->map = NULL;
}

void	load_map(t_data *data)
{
	int		fd;
	char	*line;

	data_init(data);
	fd = open(data->path_ber, O_RDONLY);
	data->w = ft_strlen(line = get_next_line(fd)) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strlen(line) - 1 != data->w)
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