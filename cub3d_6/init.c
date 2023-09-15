/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:58:46 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/15 16:36:51 by jaeyojun         ###   ########seoul.kr  */
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
	game->map_copy = NULL;
	game->height = 0;
	game->width = 0;
	game->player_count = 0;
	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
	{
		perror("Error open Error");
		exit(1);
	}
	game->img = (t_img *)malloc(sizeof(t_img));
	if (game->img == (void *)0)
		error("Error\nmalloc fail\n");
	game->img->img_no_name = NULL;
	game->img->img_so_name = NULL;
	game->img->img_we_name = NULL;
	game->img->img_ea_name = NULL;
	game->img->ceil_flag = 0;
	game->img->floor_flag = 0;
	game->mlx = mlx_init();
	if (game->mlx == (void *)0)
		error("Error\nmlx\n");
	game->player = (t_player *)malloc(sizeof(t_player));
	game->img_info = (t_img_info *)malloc(sizeof(t_img_info));
}

static char	find_location(t_game *game, char location, int i, int j)
{
	if (location == 'N')
	{
		game->player->dir_x = 1;
		game->player->plane_y = 0.66;
	}
	else if (location == 'S')
	{
		game->player->dir_x = -1;
		game->player->plane_y = -0.66;
	}
	else if (location == 'W')
	{
		game->player->dir_x = -1;
		game->player->plane_y = 0.66;
	}
	else if (location == 'E')
	{
		game->player->dir_x = 1;
		game->player->plane_y = -0.66;
	}
	else
		return (0);
	game->player->pos_x = j + 0.5;
	game->player->pos_y = i + 0.5;
	game->player->plane_x = 0;
	game->player->dir_y = 0;
	return (1);
}

void	init_player(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map_copy[i])
	{
		j = 0;
		while (game->map_copy[i][j])
		{
			if (find_location(game, game->map_copy[i][j], i, j))
				return ;
			j++;
		}
		i++;
	}
}
