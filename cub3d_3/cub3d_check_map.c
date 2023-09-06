/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:06:20 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/06 23:04:57 by jaeyojun         ###   ########seoul.kr  */
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
			if (temp[j + 1] == '\n' && temp[j] != '\0')
				error("fuck\n");
		j++;
	}
	return (temp);
}

// void	check_wall(char **map)
// {

// }

void	check_map(t_game *game)
{
	char	**map_copy;
	long	location;
	char	*one_copy;

	location = first_new_line_delete(game->map);
	one_copy = middle_new_line_check(game->map + location);
	map_copy = split_string(one_copy, '\n');

	int i = 0;
	while (map_copy[i])
	{
		printf("%s\n", map_copy[i]);
		i++;
	}
	//2차원배열에 각각 넣어줌 -> 0으로 부터 주변에 공백, 널이 있는지 검사, 위아래 양옆 전부 1인지 검사
	//check_wall(map_copy);

	free(one_copy);
	free(game->map);
}
