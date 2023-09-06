/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_read_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:03:19 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/06 21:08:16 by jaeyojun         ###   ########seoul.kr  */
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
	//int	count_newline;

	//count_newline = 0;
	i = -1;
	//printf("line : %s", line);
	while (++i < line_len)
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == ' ' \
			|| line[i] == '\n' || line[i] == '\t')
		{
			//count_newline = 1;
			continue ;
		}
		else if (line[i] == 'N' || line[i] == 'S' || \
			line[i] == 'W' || line[i] == 'E')
		{
			//count_newline = 1;
			game->player_count++;
		}
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
	// printf("line : .%s", line);
	// if (count_newline == 0 || line[0] != '\n')
	// 	error("invalid input map1\n");
	return (1);
}

void	check_dir_rgb(char *line, t_game *game, int *count)
{
	char	**temp;
	char	*no_newline;

	no_newline = no_new_line(line);
	temp = split_string(no_newline, ' ');
	if (!temp)
		error("direction Error1\n");
	if (line[0] == '\n' && !(line[1]))
	{
		char_two_free(temp);
		return ;
	}
	else if (!(str_n_compare(temp[0], "F", 1)) || \
		!(str_n_compare(temp[0], "C", 1)))
		check_rgb(no_newline, game, count);
	else if (!(str_n_compare(temp[0], "NO", 2)) || \
		!(str_n_compare(temp[0], "SO", 2)) || \
		!(str_n_compare(temp[0], "WE", 2)) || \
		!(str_n_compare(temp[0], "EA", 2)))
		check_direction(no_newline, game, count);
	else
		error("check_dir_rgb_Error\n");
	char_two_free(temp);
	free(no_newline);
}

void	read_map(t_game *game)
{
	char	*map_buf;
	char	*line;
	int		count;
	
	//count 변수를 만듦
	//1. count : 0 ~ 3일 때 이미지 파일
	//2. count : 4 ~ 5일 때 RGB
	//1,2 하다가 개행 말고 다른 게 나오면 에러 처리
	
	//개행까지 전부 읽은 다음
	//2차원배열에 각각 넣어줌 -> 0으로 부터 주변에 공백, 널이 있는지 검사, 위아래 양옆 전부 1인지 검사
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
				if (line[0] != '\n')
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
	//printf("%s\n", map_buf);
	close(game->fd);
	game->map = map_buf;
	free(line);
	//free(map_buf);
}
