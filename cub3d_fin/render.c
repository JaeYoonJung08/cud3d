/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:49:13 by naki              #+#    #+#             */
/*   Updated: 2023/09/15 18:54:14 by jaeyojun         ###   ########seoul.kr  */
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
	render->text_step = 1.0 * 64 / ray->wall_height;
	render->text_pos = (ray->draw_start - WIN_HEIGHT / 2 + \
	ray->wall_height / 2) * render->text_step;
	return ;
}

void	run_render(t_game *game, t_ray *ray, t_render *render, int x)
{
	int	y;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		render->text_y = (int)render->text_pos & 63;
		render->text_pos += render->text_step;
		render->color = \
		game->texture[render->text_num][64 * render->text_y + render->text_x];
		if (ray->side == WALL_Y)
			render->color = (render->color >> 1) & 8355711;
		game->buf[y][x] = render->color;
		y++;
	}
}

void	paint(t_game *game) //버퍼에 담긴 걸 이미지 주소에 하나하나 담는다 근데 왜 char *가 아니라 int *?
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < WIN_HEIGHT)
	{
		wid = 0;
		while (wid < WIN_WIDTH)
		{
			game->img_info->data[hei * WIN_WIDTH + wid] = game->buf[hei][wid];
			wid++;
		}
		hei++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img_info->img, 0, 0);
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
			game->buf[hei][wid] = game->img->c_color;
			game->buf[WIN_HEIGHT - hei - 1][wid] = game->img->f_color;
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
		run_dda(game);
		calculate_wall(game, &ray);
		set_render(game, &ray, &render);
		run_render(game, &ray, &render, x);
		x++;
	}
	return ;
}
