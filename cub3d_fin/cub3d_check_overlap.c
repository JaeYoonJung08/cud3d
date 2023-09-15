/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_overlap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:00:41 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/15 18:06:26 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static void	overlap_direction(char *file1, char *file2)
{
	if (!(str_n_compare(file1, file2, str_length(file2))))
		error("overlap string error\n");
}

static void	overlap_rgb(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->img->ceil[i] != game->img->floor[i])
			return ;
		i++;
	}
	error("same rgb\n");
}

void	check_overlap(t_game *game)
{
	int		i;
	int		j;
	char	*temp[5];

	i = -1;
	temp[0] = game->img->img_no_name;
	temp[1] = game->img->img_so_name;
	temp[2] = game->img->img_we_name;
	temp[3] = game->img->img_ea_name;
	temp[4] = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				continue ;
			else
				overlap_direction(temp[i], temp[j]);
		}
	}
	overlap_rgb(game);
}
