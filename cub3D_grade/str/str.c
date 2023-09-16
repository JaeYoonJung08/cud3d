/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:50:16 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 17:55:28 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	str_length(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	str_n_compare(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

long	atoi_while(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			result = (10 * result) + str[i] - '0';
		else
			error("Error\natoi invalid\n");
		i++;
	}
	if (i >= 11)
		error("Error\nlong long\n");
	return (result);
}

int	int_atoi(char *str)
{
	int		i;
	int		result;

	i = 0;
	if (str[i] == '-')
		error("Error\ninvalid_int\n");
	result = atoi_while((str + i));
	if (!((0 <= result) && (result <= 255)))
		error("Error\natoi range\n");
	return (result);
}
