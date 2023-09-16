/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:35:53 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/13 17:09:42 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*ft_check_null(char *line);
char		*ft_strdup(char *string);
char		*ft_strjoin(char *s1, char *s2, int s2_len, int count);
char		*ft_strcat(char *buff, char *prev);
char		*ft_strchr(const char *s, int c);
int			ft_strlen(const char *s);
char		*ft_substr(char *s, unsigned int start, unsigned int len);
char		*ft_substrab(char *s, unsigned int start, int len);
char		*ft_nonewline(char *line);
char		*ft_readline(int fd, char *buff, char *backup);
char		*get_next_line(int fd);

#endif