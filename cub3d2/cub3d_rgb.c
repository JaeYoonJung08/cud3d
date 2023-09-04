/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:57:50 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/05 05:23:40 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

// ','과 숫자들이 잘 들어왔는지 검사
void	check_rgb_invalid(char *temp)
{
	int		i;

	i = 0;
	while (temp[i])
	{
		if (!(temp[i] == ',' || (temp[i] >= '0' && temp[i] <= '9') ||
			temp[i] == '\n'))
			error("rgb_invalid_Erro1r\n");
		i++;
	}
}

//들어온 rgb가 잘 맞게 들어왔는지 검사하고 atoi
void	check_color(char **temp_split, int *array)
{
	int	temp_string;
	int	i;

	i = 0;
	temp_string = 0;
	while(temp_split[temp_string])
		temp_string++;
	
	// int j = 0;
	// while (temp_split[j])
	// {
	// 	printf("temp_split : %s\n", temp_split[j]);
	// 	j++;
	// }
	//split한 인자가 3개가 아니면 에러
	if (temp_string != 3)
		error("rgb_color_Error\n");
	temp_string = 0;
	while (temp_split[temp_string])
	{
		if (temp_string % 2 == 0)
		{
			array[i] = int_atoi(temp_split[temp_string]);
			i++;
		}
		temp_string++;
	}
}

//rgb ,와 숫자인지 검사 한 후 rgb 값 넣어주기
void	input_rgb(char *temp, int *count, int *array)
{
	char	**temp_split;

	check_rgb_invalid(temp);
	temp_split = split_string(temp, ',');
	if (!temp_split)
		error("rgb_input_Error\n");
	check_color(temp_split, array);
	(*count)++;
}

//rgb F와 C 체크
void	check_rgb(char *line, t_game *game, int *count)
{
	char	**temp;
	int		temp_string;
	char	*no_newline;
	
	printf("DENG\n");

	if (line[0] == '\n' && !(line[1]))
		return ;
	no_newline = no_new_line(line);
	//printf("line : %s\n", line);
	//printf("no_newline : %s\n", no_newline);
	temp = split_string(no_newline, ' ');
	if (!temp)
		error("rgb_Error\n");
	temp_string = 0;
	while (temp[temp_string])
		temp_string++;
	if (!(str_n_compare(line, "F", 1)) && temp_string == 2)
		input_rgb(temp[1], count, game->img->floor);
	else if (!(str_n_compare(line, "C", 1))  && temp_string == 2)
		input_rgb(temp[1], count, game->img->ceil);
	else
		error("rgb_Error\n");
}
