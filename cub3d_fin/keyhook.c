/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:29:12 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 16:52:23 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	move_ver(int dir, t_game *game)
{
	double	tmp_dir_x;
	double	tmp_dir_y;

	tmp_dir_x = game->player->dir_x;
	tmp_dir_y = game->player->dir_y;
	if (dir == BACK)
	{
		tmp_dir_x *= -1;
		tmp_dir_y *= -1;
	}
	if (game->map_2d[(int)(game->player->pos_x + tmp_dir_x \
		* MOVE_SPEED)][(int)(game->player->pos_y)] != '1')
		game->player->pos_x += tmp_dir_x * MOVE_SPEED;
	if (game->map_2d[(int)(game->player->pos_x)][(int) \
		(game->player->pos_y + tmp_dir_y * MOVE_SPEED)] != '1')
		game->player->pos_y += tmp_dir_y * MOVE_SPEED;
}

void	move_hor(int dir, t_game *game)
{
	if (dir == LEFT)
	{
		if (game->map_2d[(int)(game->player->pos_x - game->player->plane_x \
			* MOVE_SPEED)][(int)(game->player->pos_y)] != '1')
			game->player->pos_x -= game->player->plane_x * MOVE_SPEED;
		if (game->map_2d[(int)(game->player->pos_x)][(int) \
			(game->player->pos_y - game->player->plane_y * MOVE_SPEED)] != '1')
			game->player->pos_y -= game->player->plane_y * MOVE_SPEED;
	}
	else if (dir == RIGHT)
	{
		if (game->map_2d[(int)(game->player->pos_x + game->player->plane_x \
			* MOVE_SPEED)][(int)(game->player->pos_y)] != '1')
			game->player->pos_x += game->player->plane_x * MOVE_SPEED;
		if (game->map_2d[(int)(game->player->pos_x)][(int) \
			(game->player->pos_y + game->player->plane_y * MOVE_SPEED)] != '1')
			game->player->pos_y += game->player->plane_y * MOVE_SPEED;
	}
}

void	move_cam(int dir, t_game *game)
{
	double	olddir_x;
	double	oldplane_x;
	double	tmp_rot_speed;

	olddir_x = game->player->dir_x;
	oldplane_x = game->player->plane_x;
	tmp_rot_speed = ROT_SPEED;
	if (dir == RIGHT)
		tmp_rot_speed = -ROT_SPEED;
	game->player->dir_x = game->player->dir_x * cos(tmp_rot_speed) - \
		game->player->dir_y * sin(tmp_rot_speed);
	game->player->dir_y = olddir_x * sin(tmp_rot_speed) + \
		game->player->dir_y * cos(tmp_rot_speed);
	game->player->plane_x = game->player->plane_x * cos(tmp_rot_speed) - \
		game->player->plane_y * sin(tmp_rot_speed);
	game->player->plane_y = oldplane_x * sin(tmp_rot_speed) + \
		game->player->plane_y * cos(tmp_rot_speed);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_hook(game);
	else if (keycode == KEY_W)
		move_ver(FRONT, game);
	else if (keycode == KEY_S)
		move_ver(BACK, game);
	else if (keycode == KEY_A)
		move_hor(LEFT, game);
	else if (keycode == KEY_D)
		move_hor(RIGHT, game);
	else if (keycode == KEY_RIGHT)
		move_cam(RIGHT, game);
	else if (keycode == KEY_LEFT)
		move_cam(LEFT, game);
	else
		return (0);
	main_loop(game);
	return (0);
}
