/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:24:29 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/13 17:09:42 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd, char *line)
{
	char	buff[BUFFER_SIZE + 1];
	int		readcount;

	readcount = 1;
	while (readcount)
	{
		readcount = read(fd, buff, BUFFER_SIZE);
		if (readcount == 0)
			break ;
		else if (readcount == -1)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		buff[readcount] = '\0';
		line = ft_strjoin(line, buff, readcount, ft_strlen(line));
		if (!line)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (line);
}

static char	*ft_checkline(char *line, char **backup)
{
	int		i;
	int		len_line;

	i = 0;
	if (!line)
	{
		line = NULL;
		return (NULL);
	}
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	len_line = ft_strlen(line);
	*backup = ft_substr(line, i + 1, len_line - i);
	if (!(*backup))
		return (NULL);
	if (*backup[0] == '\0')
	{
		free(*backup);
		line = NULL;
		*backup = NULL;
		return (NULL);
	}
	return (*backup);
}

int	len_check(char *line)
{
	int	i;

	i = 0;
	if (line == 0)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*change_line(char **line, char **backup)
{
	int		count;
	char	*temp;

	if (!(*line))
		return (NULL);
	count = len_check(*line);
	if (count == -1)
		temp = ft_strdup(*line);
	else
		temp = ft_substr(*line, 0, count + 1);
	if (!temp)
	{
		free(*backup);
		*backup = NULL;
		temp = NULL;
		return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup)
	{
		line = ft_strdup(backup);
		free(backup);
		backup = NULL;
		if (!line)
			return (NULL);
	}
	else
		line = NULL;
	line = readline(fd, line);
	if (!line)
		return (NULL);
	backup = ft_checkline(line, &backup);
	temp = change_line(&line, &backup);
	free(line);
	if (!temp)
		return (NULL);
	return (temp);
}
