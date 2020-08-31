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

static int ft_endline(char *s)
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

static int	rest(char **str, int el, int len, int fd)
{
	char	*tmp;

	tmp = ft_substr(str[fd], el + 1, len);
	free(str[fd]);
	str[fd] = tmp;

	return (1);
}

static int	finishline(int fd, char **line, char **str)
{
	int	el;
	int	len;
	int	temp;

	if (str[fd] != NULL)
	{
		el = ft_endline(str[fd]);
		len = ft_strlen(str[fd]);
		temp = el;
		if (el == -1)
			el = len;
		if (el == 0)
			*line = ft_strdup("");
		else
		{
			*line = (char *)malloc(sizeof(char) * el + 1);
			ft_memcpy(*line, str[fd], el);
		}
		if (temp != -1)
			return (rest(str, el, len, fd));
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			b;
	char		*buf;
	static char	*str[256];
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
	free(buf);
	buf = NULL;
	if (b < 0)
		return (-1);
	return (finishline(fd, line, str));
}
