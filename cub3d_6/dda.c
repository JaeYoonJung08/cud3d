/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:41:00 by naki              #+#    #+#             */
/*   Updated: 2023/09/15 16:36:32 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static double  get_delta(int raydir_self, int raydir_other)
{
    if (raydir_other == 0)
        return (0);
    if (raydir_self == 0)
        return (1);
    return (fabs(1 / raydir_self));
}

static int get_step(int raydir)
{
    if (raydir < 0)
        return (-1);
    else
        return (1);
}

void set_dda(t_game *game, t_ray *ray, int *x)
{
    ray->cam_x = (2 * *x / WIN_WIDTH) - 1;
    ray->raydir_x = game->player->dir_x + game->player->plane_x * ray->cam_x;
    ray->raydir_y = game->player->dir_y + game->player->plane_y * ray->cam_x;
    ray->delta_x = get_delta(ray->raydir_x, ray->raydir_y);
    ray->delta_y = get_delta(ray->raydir_y, ray->raydir_x);
    ray->intpos_x = (int)(game->player->pos_x);
    ray->intpos_y = (int)(game->player->pos_y);
    ray->hit = 0;
    ray->step_x = get_step(ray->raydir_x);
    ray->step_y = get_step(ray->raydir_y);
    if (ray->raydir_x < 0)
        ray->distance_x = (game->player->pos_x - ray->intpos_x) * ray->delta_x;
    else
        ray->distance_x = (ray->intpos_x + 1.0 - game->player->pos_x) * ray->delta_x;
    if (ray->raydir_y < 0)
        ray->distance_y = (game->player->pos_y - ray->intpos_y) * ray->delta_y;
    else
        ray->distance_y = (ray->intpos_y + 1.0 - game->player->pos_y) * ray->delta_y;
    return ;
}

void run_dda(t_game *game)
{
    t_ray   ray;
    int     x;
    
    x = 0;
    while (x < WIN_WIDTH)
    {
        set_dda(game, &ray, &x);
        while (ray.hit == 0)
        {
            if (ray.distance_x < ray.distance_y)
            {
                ray.distance_x += ray.delta_x;
                ray.intpos_x += ray.step_x;
                ray.side = WALL_X;
            }
            else
            {
                ray.distance_y += ray.delta_y;
                ray.intpos_y += ray.step_y;
                ray.side = WALL_Y;
            }
            if (game->map[ray.intpos_x][ray.intpos_y] > '0')
                ray.hit = 1;
        }
        x++;
    }
    return ;
}

void calculate_wall(t_game *game, t_ray *ray)
{
    int wall_height;
    int start;
    int end;

    if (ray->side == WALL_X)
        ray->perp_wall = (ray->intpos_x - game->player->pos_x \
        + (1 - ray->step_x) / 2) / ray->raydir_x;
    else
        ray->perp_wall = (ray->intpos_y - game->player->pos_y \
        + (1 - ray->step_y) / 2) / ray->raydir_y;
    wall_height = (int)(WIN_HEIGHT / ray->perp_wall);
    start = (-wall_height / 2) + (WIN_HEIGHT / 2);
    if (start < 0)
        start = 0;
    end = (wall_height / 2) + (WIN_HEIGHT / 2);
    if (end >= WIN_HEIGHT)
        end = WIN_HEIGHT - 1;
    return ;
}