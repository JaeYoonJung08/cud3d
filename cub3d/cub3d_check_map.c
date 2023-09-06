/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:06:20 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/06 18:11:36 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	check_map(t_game *game)
{
	char	*map_copy;
	int		count;

	count = 0;
	map_copy = game->map;
	while (*map_copy) 
	{
		if (*map_copy == '\n')
		{
			printf("DENUG\n");
			exit(0);
		}
	}
}
