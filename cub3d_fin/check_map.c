/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:06:20 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 16:22:59 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

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
	char	**map_2d;
	long	location;
	char	*one_copy;
	int		hei;

	hei = 0;
	if (game->player_count >= 2 || game->player_count == 0)
		error("Error\nplay_direction\n");
	location = first_new_line_delete(game->map);
	one_copy = middle_new_line_check(game->map + location);
	map_2d = split_string(one_copy, '\n');
	if (map_2d == (void *)0)
		error("Error\nmap malloc fail\n");
	check_zero(map_2d);
	check_wall(map_2d);
	game->map_2d = map_2d;
	while (game->map_2d[hei])
		hei++;
	game->height = hei;
	free(one_copy);
	free(game->map);
}
