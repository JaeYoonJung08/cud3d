/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:37:44 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/07 18:38:11 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	startend_one_check(char *map)
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
	//처음과 마지막 1체크
	if (map[first_one] != '1' && map[count - 1] != '1')
		error("ERROR\n");
}

int	strend_line_check(char *map)
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

void	check_wall(char **map)
{
	//1. 한 줄씩 양옆이 1인지 검사
	//2. 처음과 마지막이 전부 1인지 검사.
	int	i;
	int	end_line;

	i = 0;
	end_line = 0;
	while (map[end_line])
		end_line++;
	//처음과 마지막 줄이 공백과 1로 이루어져있는지 검사
	if (strend_line_check(map[0]) || strend_line_check(map[end_line - 1]))
		error("ERROR1\n");
	//양옆이 1인지 검사
	while (map[i])
	{
		startend_one_check(map[i]);
		i++;
	}
}