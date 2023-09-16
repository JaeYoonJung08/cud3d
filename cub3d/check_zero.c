/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:39:23 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 16:23:21 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static int	valid_check(char c)
{
	if (c == '\0' || c == ' ')
		return (1);
	return (0);
}

static void	ensw_diagonal_check(char **map, int i, int j)
{
	if (map[i - 1] && valid_check(map[i - 1][j]))
		error("Error\ninvalid map\n");
	else if (map[i - 1] && valid_check(map[i - 1][j - 1]))
		error("Error\ninvalid map\n");
	else if (map[i - 1] && valid_check(map[i - 1][j + 1]))
		error("Error\ninvalid map\n");
	else if (map[i] && valid_check(map[i][j - 1]))
		error("Error\ninvalid map\n");
	else if (map[i] && valid_check(map[i][j + 1]))
		error("Error\ninvalid map\n");
	else if (map[i + 1] && valid_check(map[i + 1][j]))
		error("Error\ninvalid map\n");
	else if (map[i + 1] && valid_check(map[i + 1][j - 1]))
		error("Error\ninvalid map\n");
	else if (map[i + 1] && valid_check(map[i + 1][j + 1]))
		error("Error\ninvalid map\n");
}

void	check_zero(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' \
				|| map[i][j] == 'S' || map[i][j] == 'W' \
				|| map[i][j] == 'E')
				ensw_diagonal_check(map, i, j);
			j++;
		}
		i++;
	}
}
