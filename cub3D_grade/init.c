/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:58:46 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 16:43:27 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	main_loop(t_game *game)
{
	set_fnc(game);
	raycasting(game);
	paint(game);
}

static void	init_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->text[i].path = NULL;
		game->text[i].img = NULL;
		game->text[i].data = NULL;
		i++;
	}
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
	init_texture(game);
	game->color->ceil_flag = 0;
	game->color->floor_flag = 0;
}

static char	find_location(t_game *game, char location, int i, int j)
{
	game->player->pos_x = i + 0.5;
	game->player->pos_y = j + 0.5;
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
		game->player->dir_y = -1;
		game->player->plane_x = -0.66;
	}
	else if (location == 'E')
	{
		game->player->dir_y = 1;
		game->player->plane_x = 0.66;
	}
	else
		return (0);
	return (1);
}

void	init_player(t_game *game)
{
	int		i;
	int		j;

	game->player->plane_x = 0;
	game->player->plane_y = 0;
	game->player->dir_x = 0;
	game->player->dir_y = 0;
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
