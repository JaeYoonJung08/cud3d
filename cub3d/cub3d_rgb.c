/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:57:50 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/05 02:12:15 by jaeyojun         ###   ########seoul.kr  */
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
		if (!(temp[i] == ',' && (temp[i] >= '0' && temp[i] <= '9')))
			error("Error\n");
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
	//split한 인자가 5개가 아니면 에러
	if (temp_string != 5)
		error("Error\n");
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
		error("Error\n");
	check_color(temp_split, array);
	(*count)++;
}

//rgb F와 C 체크
void	check_rgb(char *line, t_game *game, int *count)
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
	else if (!(str_n_compare(line, "F", 1)) && temp_string == 2)
		input_rgb(temp[1], count, game->img->floor);
	else if (!(str_n_compare(line, "C", 1))  && temp_string == 2)
		input_rgb(temp[1], count, game->img->ceil);
	else
		error("Error\n");
}
