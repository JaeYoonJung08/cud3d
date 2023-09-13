/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:15:13 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/13 17:44:14 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static void	put_mlx_img(t_game *game, char *temp, void **location)
{
	int	wid;
	int	hei;

	*location = mlx_xpm_file_to_image(game->mlx, temp, &wid, &hei);
	if (!(*location))
		error("put_img_Error1\n");
}

static void	put_img(int *count, t_game *game, char *temp, int flag)
{
	char	*copy;

	copy = copy_string(temp);
	if (flag == NO)
	{
		put_mlx_img(game, temp, &(game->img->img_no));
		game->img->img_no_name = copy;
	}
	else if (flag == SO)
	{
		put_mlx_img(game, temp, &(game->img->img_so));
		game->img->img_so_name = copy;
	}
	else if (flag == EA)
	{
		put_mlx_img(game, temp, &(game->img->img_ea));
		game->img->img_we_name = copy;
	}
	else if (flag == WE)
	{
		put_mlx_img(game, temp, &(game->img->img_we));
		game->img->img_ea_name = copy;
	}
	(*count)++;
}

static void	check_extension(char *file)
{
	int	length;

	length = str_length(file);
	if (length <= 4)
		error("extension error\n");
	if (!(file[length - 1] == 'm' && file[length - 2] == 'p' \
		&& file[length - 3] == 'x' && file[length - 4] == '.'))
		error("extesion error\n");
}

void	direction_chose(int	*count, t_game *game, char *new_line, char *temp)
{
	if (!(str_n_compare(temp, "NO", str_length(temp))) && \
		!(game->img->img_no_name))
		put_img(count, game, new_line, NO);
	else if (!(str_n_compare(temp, "SO", str_length(temp))) \
		&& !(game->img->img_so_name))
		put_img(count, game, new_line, SO);
	else if (!(str_n_compare(temp, "WE", str_length(temp))) \
		&& !(game->img->img_we_name))
		put_img(count, game, new_line, EA);
	else if (!(str_n_compare(temp, "EA", str_length(temp))) \
		&& !(game->img->img_ea_name))
		put_img(count, game, new_line, WE);
	else
		error("direction Error2\n");
}

void	check_direction(char *line, t_game *game, int *count)
{
	char	**temp;
	int		temp_string;
	char	*new_line;

	new_line = NULL;
	temp = split_string(line, ' ');
	if (!temp)
		error("direction Error1\n");
	temp_string = 0;
	while (temp[temp_string])
		temp_string++;
	if (temp_string == 2)
	{
		new_line = no_new_line(temp[1]);
		check_extension(new_line);
	}
	if (temp_string == 2)
		direction_chose(count, game, new_line, temp[0]);
	else
		error("direction Error2\n");
	char_two_free(temp);
	free(new_line);
}
