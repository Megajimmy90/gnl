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

int ft_endline(char *s)
{
	int i;

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

int finishline(int fd, char **line, char **str)
{
	int el;
	char *tmp;
	int len;
	int temp;

	if (str[fd] != NULL)
	{
		el = ft_endline(str[fd]);
		len = ft_strlen(str[fd]);
		temp = el;
		if (el == -1)
			el = len;
		*line = (char *)malloc(sizeof(char) * el + 1);
		ft_memcpy(*line, str[fd], el);

		if (temp != -1)
		{
			tmp = ft_substr(str[fd], el + 1, len);
			free(str[fd]);
			str[fd] = tmp;
			return (1);
		}
	}
	else
	{
		free(str[fd]);
		str[fd] = NULL;
	}
	*line = ft_strdup("");
	return (0);
}

int get_next_line(int fd, char **line)
{
	int b;
	char *buf;
	static char *str[256];

	if (fd < 0 || BUFFER_SIZE <= 0 || !(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((b = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[b] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
		if (ft_endline(str[fd]) >= 0)
			break;
	}
	free(buf);
	buf = NULL;
	if (b < 0)
		return (-1);
	return (finishline(fd, line, str));
}

int main()
{
	char *prueba;
	int fd = open("prueba.txt", O_RDONLY);

	int i = 0;
	while (get_next_line(fd, &prueba))
	{	
		printf("%s\n", prueba);
		free(prueba);
		i++;
	}
	printf("%s\n", prueba);
	
}