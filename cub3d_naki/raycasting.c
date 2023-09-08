/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:25:31 by naki              #+#    #+#             */
/*   Updated: 2023/09/08 17:01:04 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int setting(t_game *game)
{
    double  camX
}

int get_hit(t_game *game, int *hit, int *side);

int raycasting(t_game *game)
{
    int x;
    int hit;
    int side;

    x = 0;
    side = 0;
    while (x < game->width)
    {
        setting(game);
        hit = 0;
        while (hit == 0)
            get_hit(game, &hit, &side);
        
    }
}

int floor_n_ceil(t_game *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->width)
    {
        y = 0;
        while (y < game->height)
        {
            game->buf[y][x] = game->c_color;
            game->buf[game->height - y - 1][x] = game->f_color;
            y++;
        }
        x++;
    }
    return (draw(game));
}

int paint(t_game *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->width) //height width 순서 바꿔도 괜찮은지?
    {
        y = 0;
        while (y < game->height)
        {
            game->img.data[y * game->width + x] = game->buf[y][x];
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
