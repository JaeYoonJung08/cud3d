/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:15:13 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/07 14:41:07 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

char	*no_new_line(char *line)
{
	int		i;
	char	*no_newline;

	if (!line)
		return (NULL);
	no_newline = malloc(sizeof(char) * (str_length(line) - 1));
	i = 0;
	while (line[i])
	{
		no_newline[i] = line[i];
		if (line[i] == '\n')
			break ;
		i++;
	}
	no_newline[i] = '\0';
	return (no_newline);
}

void	put_img(int *count, t_game *game, char *temp, int flag)
{
	int		wid;
	int		hei;

	if (flag == NO)
	{
		game->img->img_no = mlx_xpm_file_to_image(game->mlx, temp, &wid, &hei);
		if (!(game->img->img_no))
			error("put_img_Error1\n");
	}
	else if (flag == SO)
	{
		game->img->img_so = mlx_xpm_file_to_image(game->mlx, temp, &wid, &hei);
		if (!(game->img->img_so))
			error("put_img_Error2\n");
	}
	else if (flag == EA)
	{
		game->img->img_ea = mlx_xpm_file_to_image(game->mlx, temp, &wid, &hei);
		if (!(game->img->img_ea))
			error("put_img_Erro3\n");
	}
	else if (flag == WE)
	{
		game->img->img_we = mlx_xpm_file_to_image(game->mlx, temp, &wid, &hei);
		if (!(game->img->img_we))
			error("put_img_Error4\n");
	}
	(*count)++;
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
		new_line = no_new_line(temp[1]);
	if (!(str_n_compare(temp[0], "NO", str_length(temp[0]))) && temp_string == 2)
		put_img(count, game, new_line, NO);
	else if (!(str_n_compare(temp[0], "SO", str_length(temp[0]))) && temp_string == 2)
		put_img(count, game, new_line, SO);
	else if (!(str_n_compare(temp[0], "WE", str_length(temp[0]))) && temp_string == 2)
		put_img(count, game, new_line, EA);
	else if (!(str_n_compare(temp[0], "EA", str_length(temp[0]))) && temp_string == 2)
		put_img(count, game, new_line, WE);
	else
		error("direction Error\n");
	char_two_free(temp);
	free(new_line);
}
