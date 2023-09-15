/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:29:12 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/15 16:31:48 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_info->img);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void    move_ver(int dir, t_game *game)
{
    if (dir == FRONT)
    {
        if (game->map[(int)(game->player->pos_x + game->player->dir_x * MOVE_SPEED)]\
        [(int)(game->player->pos_y)] != '0')
            game->player->pos_x += game->player->dir_x * MOVE_SPEED;
        if (game->map[(int)(game->player->pos_x)][(int)(game->player->pos_y + \
        game->player->dir_y * MOVE_SPEED)] != '0')
            game->player->pos_y += game->player->dir_y * MOVE_SPEED;
    }
    else if (dir == BACK)
    {
        if (game->map[(int)(game->player->pos_x - game->player->dir_x * MOVE_SPEED)]\
        [(int)(game->player->pos_y)] != '0')
            game->player->pos_x -= game->player->dir_x * MOVE_SPEED;
        if (game->map[(int)(game->player->pos_x)][(int)(game->player->pos_y - \
        game->player->dir_y * MOVE_SPEED)] != '0')
            game->player->pos_y -= game->player->dir_y * MOVE_SPEED;
    }
    return ;
}

void    move_hor(int dir, t_game *game)
{
    int tmpdir_x;
    int tmpdir_y;
    
    if (dir == LEFT)
    {
        if (game->map[(int)(game->player->pos_x)]\
        [(int)(game->player->pos_y - game->player->dir_y * MOVE_SPEED)] != '0')
            game->player->pos_y -= game->player->dir_x * MOVE_SPEED;
        if (game->map[(int)(game->player->pos_x)][(int)(game->player->pos_y + \
        game->player->dir_y * MOVE_SPEED)] != '0')
            game->player->pos_y += game->player->dir_y * MOVE_SPEED;
    }
    else if (dir == RIGHT)
    {
    }

    tmpdir_x = game->player->pos_x * cos(M_PI / 2) - \
    game->player->pos_y * sin(M_PI / 2);
	tmpdir_y = game->player->pos_x * sin(M_PI / 2) + \
    game->player->dir_y * cos(M_PI / 2);
	x = (int)(game->p_info.pos.x - dir.x * MOVE_SPEED * axis);
	y = (int)(game->p_info.pos.y + dir.y * MOVE_SPEED * axis);
	if (game->map[(int)(game->p_info.pos.y)][x] == '0')
		game->p_info.pos.x -= dir.x * MOVE_SPEED * axis;
	if (game->map[y][(int)(game->p_info.pos.x)] == '0')
		game->p_info.pos.y += dir.y * MOVE_SPEED * axis;
    return ;
}

void    move_cam(int dir, t_game *game)
{
    double  olddir_x;
    double  oldplane_x;
    if (dir == LEFT)
    {
        olddir_x = game->player->dir_x;
        game->player->dir_x = game->player->dir_x * cos(ROT_SPEED) - \
        game->player->dir_y * sin(ROT_SPEED);
        game->player->dir_y = olddir_x * sin(ROT_SPEED) + \
        game->player->dir_y * cos(ROT_SPEED);
        oldplane_x = game->player->plane_x;
        game->player->plane_x = game->player->plane_x * cos(ROT_SPEED) - \
        game->player->plane_y * sin(ROT_SPEED);
        game->player->plane_y = oldplane_x * sin(ROT_SPEED) + \
        game->player->plane_y * cos(ROT_SPEED);
    }
    else if (dir == RIGHT)
    {
        olddir_x = game->player->dir_x;
        game->player->dir_x = game->player->dir_x * cos(-ROT_SPEED) - \
        game->player->dir_y * sin(-ROT_SPEED);
        game->player->dir_y = olddir_x * sin(-ROT_SPEED) + \
        game->player->dir_y * cos(-ROT_SPEED);
        oldplane_x = game->player->plane_x;
        game->player->plane_x = game->player->plane_x * cos(-ROT_SPEED) - \
        game->player->plane_y * sin(-ROT_SPEED);
        game->player->plane_y = oldplane_x * sin(-ROT_SPEED) + \
        game->player->plane_y * cos(-ROT_SPEED);
    }
    return ;
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_hook(game);
    if (keycode == KEY_W)
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