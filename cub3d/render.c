/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:49:13 by naki              #+#    #+#             */
/*   Updated: 2023/09/16 14:54:39 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	set_render(t_game *game, t_ray *ray, t_render *render)
{
	if (ray->side == WALL_X)
		render->side_x = game->player->pos_y + \
			ray->perp_wall * ray->raydir_y;
	else
		render->side_x = game->player->pos_x + \
			ray->perp_wall * ray->raydir_x;
	render->side_x -= floor(render->side_x);
	render->text_x = (int)(render->side_x * (double)64);
	if (ray->side == WALL_X && ray->raydir_x > 0)
		render->text_x = 64 - render->text_x - 1;
	if (ray->side == WALL_Y && ray->raydir_y < 0)
		render->text_x = 64 - render->text_x - 1;
}

void	run_render(t_game *game, t_ray *ray, t_render *render, int x)
{
	int	y;

	render->text_step = 1.0 * 64 / ray->wall_height;
	render->text_pos = (ray->draw_start - WIN_HEIGHT / 2 + \
	ray->wall_height / 2) * render->text_step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		render->text_y = (int)render->text_pos & 63;
		render->text_pos += render->text_step;
		render->color = game->text[render->text_num].data[64 * \
		render->text_y + render->text_x];
		if (ray->side == WALL_Y)
			render->color = (render->color >> 1) & 8355711;
		game->buf[y][x] = render->color;
		y++;
	}
}

void	paint(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			game->img->data[y * WIN_WIDTH + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}

void	set_fnc(t_game *game)
{
	int	wid;
	int	hei;

	wid = 0;
	while (wid < WIN_WIDTH)
	{
		hei = 0;
		while (hei < WIN_HEIGHT / 2)
		{
			game->buf[hei][wid] = game->color->c_color;
			game->buf[WIN_HEIGHT - hei - 1][wid] = game->color->f_color;
			hei++;
		}
		wid++;
	}
}

void	raycasting(t_game *game)
{
	t_ray		ray;
	t_render	render;
	int			x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		set_dda(game, &ray, x);
		run_dda(game, &ray);
		calculate_wall(game, &ray);
		set_render(game, &ray, &render);
		set_text_num(&ray, &render);
		run_render(game, &ray, &render, x);
		x++;
	}
}
