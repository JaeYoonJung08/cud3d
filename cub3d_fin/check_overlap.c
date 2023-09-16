/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overlap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:00:41 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 16:46:13 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static void	overlap_direction(char *file1, char *file2)
{
	if (!(str_n_compare(file1, file2, str_length(file2))))
		error("Error\noverlap rgb\n");
}

static void	overlap_rgb(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->color->ceil[i] != game->color->floor[i])
			return ;
		i++;
	}
	error("Error\nsame rgb\n");
}

void	check_overlap(t_game *game)
{
	int		i;
	int		j;
	char	*temp[5];

	i = -1;
	temp[0] = game->text[NO].path;
	temp[1] = game->text[SO].path;
	temp[2] = game->text[WE].path;
	temp[3] = game->text[EA].path;
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
