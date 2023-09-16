/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:03:19 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 17:53:44 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	line_string_count(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

static int	check_line(char *line, int line_len, t_game *game)
{
	int	i;

	i = -1;
	while (++i < line_len)
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == ' ' \
			|| line[i] == '\n')
			continue ;
		else if (line[i] == 'N' || line[i] == 'S' || \
			line[i] == 'W' || line[i] == 'E')
			game->player_count++;
		else
		{
			if (line_len - 1 == i)
			{
				if (line[i] != '\n')
					return (0);
			}
			else
				return (0);
		}
	}
	return (1);
}

static void	check_dir_rgb(char *line, t_game *game, int *count)
{
	char	**temp;

	temp = split_string(line, ' ');
	if (temp == (void *)0 || temp[0] == (void *)0)
		error("Error\ndir_rgb_split\n");
	if (line[0] == '\n' && !(line[1]))
	{
		char_two_free(temp);
		return ;
	}
	else if (!(str_n_compare(temp[0], "F", 1)) || \
		!(str_n_compare(temp[0], "C", 1)))
		check_rgb(line, game, count);
	else if (!(str_n_compare(temp[0], "NO", 2)) || \
		!(str_n_compare(temp[0], "SO", 2)) || \
		!(str_n_compare(temp[0], "WE", 2)) || \
		!(str_n_compare(temp[0], "EA", 2)))
		check_direction(line, game, count);
	else
		error("Error\ninvalid dir_rgb\n");
	char_two_free(temp);
}

static int	map_check(char **line, char **map_buf, t_game *game)
{
	if (check_line(*line, str_length(*line), game) == 1)
	{
		*map_buf = ft_strjoin(*map_buf, *line, \
		str_length(*line), str_length(*map_buf));
		return (0);
	}
	else
	{
		free(*map_buf);
		free(*line);
		*map_buf = NULL;
		*line = NULL;
		return (1);
	}
}

void	read_map(t_game *game)
{
	char	*map_buf;
	char	*line;
	int		count;

	map_buf = NULL;
	line = NULL;
	count = 0;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		if (count <= 5)
			check_dir_rgb(line, game, &count);
		else
			if (map_check(&line, &map_buf, game) == 1)
				error("Error\ninvalid input map\n");
		free(line);
		line = NULL;
	}
	close(game->fd);
	game->map = map_buf;
	free(line);
}
