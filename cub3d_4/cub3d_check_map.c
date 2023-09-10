/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:06:20 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/10 16:03:12 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

//1차원으로 읽어온 맵에서 개행만 삭제해주기
long	first_new_line_delete(char *map)
{
	long		i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '\n')
			break ;
		i++;
	}
	return (i);
}

//맵에서 개행으로 인해 끊어진 부분이 있는지 체크
char	*middle_new_line_check(char	*map)
{
	char	*temp;
	int		j;

	j = 0;
	temp = ft_strdup(map);
	while (temp[j])
	{
		if (temp[j] == '\n')
			if (temp[j + 1] == '\n' && temp[j] != '\0' && temp[j + 1])
				error("fuck\n");
		j++;
	}
	return (temp);
}

// int	only_space(char *line)
// {
// 	const char	tmp[6] = {
// 		'0',
// 		'1',
// 		'N',
// 		'S',
// 		'W',
// 		'E',
// 	};
// 	int			i;
// 	int			j;

// 	i = -1;
// 	if (line[0] == '\0')
// 		return (free(line), 1);
// 	while (line[++i])
// 	{
// 		j = 0;
// 		while (j < 6)
// 		{
// 			if (line[i] == tmp[j])
// 				return (free(line), 1);
// 			j++;
// 		}
// 	}
// 	return (free(line), error("Error\n"), 0);
// }

void	check_map(t_game *game)
{
	char	**map_copy;
	long	location;
	char	*one_copy;
	int		hei;

	hei = 0;
	//player가 2이상 있을 때  에러
	if (game->player_count >= 2 || game->player_count == 0)
		error("play_direction error\n");
	//연속으로 개행있는지 체크
	location = first_new_line_delete(game->map);
	one_copy = middle_new_line_check(game->map + location);
	map_copy = split_string(one_copy, '\n');
	if (map_copy == (void *)0)
		error("map two error\n");
	//2차원배열에 각각 넣어줌 -> 0으로 부터 주변에 공백, 널이 있는지 검사
	
	// int i = 0;
	// int flag = 0;
	if (only_space(map_copy[0]) == 1)
		error("first error\n");

	check_zero(map_copy);
	//양옆이 벽인지 검사
	check_wall(map_copy);
	game->map_copy = map_copy;
	while (game->map_copy[hei])
		hei++;
	game->height = hei;
	free(one_copy);
	free(game->map);
}
