/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_read_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:03:19 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/07 14:42:39 by jaeyojun         ###   ########seoul.kr  */
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

int	check_line(char *line, int line_len, t_game *game)
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
					error("invalid input map\n");
			}
			else
				error("invalid input map1\n");
		}
	}
	return (1);
}

void	check_dir_rgb(char *line, t_game *game, int *count)
{
	char	**temp;

	temp = split_string(line, ' ');
	if (!temp)
		error("direction Error1\n");
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
		error("check_dir_rgb_Error\n");
	char_two_free(temp);
}

int	check_space(char *line)
{
	const char	tmp[6] = {
		'0',
		'1',
		'N',
		'S',
		'W',
		'E'
	};
	int			i;
	int			j;

	i = -1;
	if (line[0] == '\0')
		return (free(line), 1);
	while (line[++i])
	{
		j = 0;
		while (j < 6)
		{
			if (line[i] == tmp[j])
				return (free(line), 1);
			j++;
		}
	}
	return (free(line), error("Error\n"), 0);
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
		{
			if (check_line(line, str_length(line), game) == 1)
			{
				if (check_space(no_new_line(line)) == 1)
					map_buf = ft_strjoin(map_buf, line, \
					str_length(line), str_length(map_buf));
			}
			else
			{
				free(map_buf);
				break ;
			}
		}
		free(line);
		line = NULL;
	}
	close(game->fd);
	game->map = map_buf;
	free(line);
}
