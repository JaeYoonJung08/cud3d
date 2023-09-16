/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:37:12 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 11:47:35 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	set_text_num(t_ray *ray, t_render *render)
{
	if (ray->side == WALL_X)
	{
		render->text_num = NO;
		if (ray->raydir_x > 0)
			render->text_num = SO;
	}
	if (ray->side == WALL_Y)
	{
		render->text_num = WE;
		if (ray->raydir_y > 0)
			render->text_num = EA;
	}
}
