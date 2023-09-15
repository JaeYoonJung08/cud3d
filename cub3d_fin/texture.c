/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:37:12 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/15 17:40:53 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static void    load_image(t_game *game, int *texture, char *path, t_img_info *img_info)
{
    int x;
    int y;
    
    img_info->img = mlx_xpm_file_to_image(game->mlx, path, &img_info->width, \
    &img_info->height);
    img_info->data = (int *)mlx_get_data_addr(img_info->img, &img_info->bpp, \
    &img_info->size_l, &img_info->endian);
    y = 0;
    while (y < img_info->height)
    {
        x = 0;
        while (x < img_info->width)
            texture[img_info->width * y + x] = img_info->data[img_info->width * y + x];
        y++;
    }
    mlx_destroy_image(game->mlx, img_info->img);
}

void    load_texture(t_game *game)
{
    t_img_info    img_info;

    load_image(game, game->texture[0], "texture/north.xpm", &img_info);
    load_image(game, game->texture[1], "texture/east.xpm", &img_info);
    load_image(game, game->texture[2], "texture/west.xpm", &img_info);
    load_image(game, game->texture[3], "texture/south.xpm", &img_info);
}

void    init_texture(t_game *game)
{
    int i;
    int j;

    if (!(game->texture = (int **)malloc(sizeof(int *) * 4)))
        error("Error\n");
    i = 0;
    while (i < 4)
    {
        if (!(game->texture[i] = (int *)malloc(sizeof(int) * (64 * 64))))
            error("Error\n");
        i++;
    }
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 64 * 64)
        {
            game->texture[i][j] = 0;
            j++;
        }
    }
}