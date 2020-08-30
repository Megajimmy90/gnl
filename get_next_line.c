/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-r <dnieto-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 15:00:05 by dnieto-r          #+#    #+#             */
/*   Updated: 2020/08/29 15:00:05 by dnieto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int		ft_endline(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		finishline(int fd, char **line, char **str)
{
	int		el;
	char	*tmp;
	int		len;
	
	if (str[fd] != NULL)
	{
		el = ft_endline(str[fd]);
		len = ft_strlen(str[fd]);
		if (el == -1)
		{
			el = len;
			*line = (char *)malloc(sizeof(char) * el);
			ft_memcpy(*line, str[fd], el);
			str[fd] = NULL;
			free(str[fd]);
		}
		else
		{
			*line = (char *)malloc(sizeof(char) * el);
			ft_memcpy(*line, str[fd], el);
			tmp = ft_substr(str[fd], el + 1, len);
			free(str[fd]);
			str[fd] = tmp;
		}
	}
	else
		*line = ft_strdup("");
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			b;
	char		*buf;
	static char *str[4096];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((b = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[b] = '\0';
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_endline(str[fd]) >= 0)
			break;
	}
	buf = NULL;
	free(buf);
	if (b < 0)
		return (-1);
	return (finishline(fd, line, str));
}
