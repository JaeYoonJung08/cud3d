/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:06:20 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/15 16:28:15 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

//1차원으로 읽어온 맵에서 개행만 삭제해주기
static long	first_new_line_delete(char *map)
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
static char	*middle_new_line_check(char	*map)
{
	char	*temp;
	int		j;

	j = 0;
	temp = copy_string(map);
	while (temp[j])
	{
		if (temp[j] == '\n')
			if (temp[j + 1] == '\n' && temp[j] != '\0' && temp[j + 1])
				error("Error\nmap\n");
		j++;
	}
	return (temp);
}

void	check_map(t_game *game)
{
	char	**map_copy;
	long	location;
	char	*one_copy;
	int		hei;

	hei = 0;
	if (game->player_count >= 2 || game->player_count == 0)
		error("Error\nplay_direction\n");
	location = first_new_line_delete(game->map);
	one_copy = middle_new_line_check(game->map + location);
	map_copy = split_string(one_copy, '\n');
	if (map_copy == (void *)0)
		error("Error\nmap malloc fail\n");
	if (only_space(map_copy[0]) == 1)
		error("Error\ninvalid error\n");
	check_zero(map_copy);
	check_wall(map_copy);
	game->map_copy = map_copy;
	while (game->map_copy[hei])
		hei++;
	game->height = hei;
	free(one_copy);
	free(game->map);
}
