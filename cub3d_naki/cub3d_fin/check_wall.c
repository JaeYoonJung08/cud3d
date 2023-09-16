/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:37:44 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 00:24:36 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static void	startend_one_check(char *map)
{
	int	count;
	int	first_one;

	count = str_length(map);
	first_one = 0;
	while (map[first_one])
	{
		if (map[first_one] == '1')
			break ;
		first_one++;
	}
	if (map[first_one] != '1' && map[count - 1] != '1')
		error("Error\nfirst_end_wall\n");
}

static int	strend_line_check(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != ' ' && map[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	only_space(char *map)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (map[i])
	{
		if (map[i] != ' ')
			flag = 0;
		i++;
	}
	return (flag);
}

void	check_wall(char **map)
{
	int	i;
	int	end_line;

	end_line = 0;
	while (map[end_line])
		end_line++;
	if (strend_line_check(map[0]) || strend_line_check(map[end_line - 1]))
		error("Error\nwall\n");
	i = -1;
	while (map[++i])
	{
		if (only_space(map[i]) == 1)
			continue ;
		startend_one_check(map[i]);
	}
}
