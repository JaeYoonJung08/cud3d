/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:39:23 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/07 18:42:39 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

//널문자나 공백이 있으면 에러
int	valid_check(char c)
{
	if (c == '\0' || c == ' ')
		return (1);
	return (0);
}

//0주변 8개 다  검사하는 코드
void	ensw_diagonal_check(char **map, int i, int j)
{
	if (map[i - 1] && valid_check(map[i - 1][j]))
		error("ivalid input error\n");
	else if (map[i - 1] && valid_check(map[i - 1][j - 1]))
		error("ivalid input error\n");
	else if (map[i - 1] && valid_check(map[i - 1][j + 1]))
		error("ivalid input error\n");
	else if (map[i] && valid_check(map[i][j - 1]))
		error("ivalid input error\n");
	else if (map[i] && valid_check(map[i][j + 1]))
		error("ivalid input error\n");
	else if (map[i + 1] && valid_check(map[i + 1][j]))
		error("ivalid input error\n");
	else if (map[i + 1] && valid_check(map[i + 1][j - 1]))
		error("ivalid input error\n");
	else if (map[i + 1] && valid_check(map[i + 1][j + 1]))
		error("ivalid input error\n");
}

//0 위, 아래, 양옆, 대각선 전부 널, 공백인지 아닌지 체크
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
			if (map[i][j] == '0')
				ensw_diagonal_check(map, i, j);
			j++;
		}
		i++;
	}
}
