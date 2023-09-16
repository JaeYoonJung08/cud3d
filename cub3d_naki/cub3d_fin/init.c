/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:58:46 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 15:31:38 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	main_loop(t_game *game)
{
	set_fnc(game);
	raycasting(game);
	paint(game);
}

void	init_game(t_game *game, char *file)
{
	game->map = NULL;
	game->map_2d = NULL;
	game->height = 0;
	game->player_count = 0;
	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
	{
		perror("Error\nopen Error");
		exit(1);
	}
	game->color = (t_color *)malloc(sizeof(t_color));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->img = (t_img *)malloc(sizeof(t_img));
	if (game->color == (void *)0 || game->player == (void *)0 || \
	game->img == (void *)0)
		error("Error\nmalloc fail\n");
	game->text[0].path = NULL;
	game->text[1].path = NULL;
	game->text[2].path = NULL;
	game->text[3].path = NULL;
	// game->text[0].img = NULL;
	// game->text[1].img = NULL;
	// game->text[2].img = NULL;
	// game->text[3].img = NULL;
	// game->text[0].data = NULL;
	// game->text[1].data = NULL;
	// game->text[2].data = NULL;
	// game->text[3].data = NULL;
	game->color->ceil_flag = 0;
	game->color->floor_flag = 0;
}

static char	find_location(t_game *game, char location, int i, int j)
{
	if (location == 'N')
	{
		game->player->dir_x = -1;
		game->player->plane_y = 0.66;
	}
	else if (location == 'S')
	{
		game->player->dir_x = 1;
		game->player->plane_y = -0.66;
	}
	else if (location == 'W')
	{
		game->player->dir_x = -1;
		game->player->plane_y = -0.66;
	}
	else if (location == 'E')
	{
		game->player->dir_x = 1;
		game->player->plane_y = 0.66;
	}
	else
		return (0);
	return (game->player->pos_x = i + 0.5, game->player->pos_y = j + 0.5, \
		game->player->plane_x = 0, game->player->dir_y = 0, 1);
}

void	init_player(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map_2d[i])
	{
		j = 0;
		while (game->map_2d[i][j])
		{
			if (find_location(game, game->map_2d[i][j], i, j))
				return ;
			j++;
		}
		i++;
	}
}
