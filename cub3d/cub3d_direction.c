/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:15:13 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/05 02:08:22 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	put_img(void *direction, int *count, t_game *game, char *temp)
{
	int	width;
	int	height;

	direction = mlx_xpm_file_to_image(game->mlx_ptr, \
	temp, &width, &height);
	if (!direction)
		error("Error\n");
	(*count)++;
}

void	check_direction(char *line, t_game *game, int *count)
{
	char	**temp;
	int		temp_string;

	temp = split_string(line, ' ');
	if (!temp)
		error("Error\n");
	temp_string = 0;
	while (temp[temp_string])
		temp_string++;
	if (line[0] == '\n' && !(line[1]) && temp_string == 1)
		;
	else if (!(str_n_compare(temp[0], "NO", 2)) && temp_string == 2)
		put_img(game->img->img_no, count, game, temp[1]);
	else if (!(str_n_compare(temp[0], "SO", 2)) && temp_string == 2)
		put_img(game->img->img_so, count, game, temp[1]);
	else if (!(str_n_compare(temp[0], "WE", 2)) && temp_string == 2)
		put_img(game->img->img_we, count, game, temp[1]);
	else if (!(str_n_compare(temp[0], "EA", 2)) && temp_string == 2)
		put_img(game->img->img_ea, count, game, temp[1]);
	else
		error("Error\n");
}
