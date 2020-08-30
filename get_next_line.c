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
		return (0);
	while (s[i])
	{

		if (s[i] == '\n' || s[i] == '\0')
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

	el = ft_endline(str[fd]);
	len = ft_strlen(str[fd]);
	if (el == -1)
	{
		el = len;
		*line = (char *)malloc(sizeof(char) * el);
		ft_memcpy(*line, str[fd], el);
		free(str[fd]);
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * el);
		ft_memcpy(*line, str[fd], el - 1);
		tmp = ft_substr(str[fd], el + 1, len);
		free(str[fd]);
		str[fd] = tmp;
	}

	return (1);
}

int get_next_line(int fd, char **line)
{
	int b;
	char *buf;
	static char *str[4096];
	char *tmp;
	int cont;
	cont = 1;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((b = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[b] = '\0';
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_endline(str[fd]) > 0)
			break;
	}
	free(buf);
	if (b < 0)
		return (-1);

	return (finishline(fd, line, str));
}

int main(void)
{
	int fd = open("prueba.txt", O_RDONLY);
	char **prueba;
	prueba = (char **)malloc(sizeof(char *) * 100);

	get_next_line(fd, prueba);
	printf("%s\n", prueba[0]);
	get_next_line(fd, prueba);
	printf("%s\n", prueba[0]);
	get_next_line(fd, prueba);
	printf("%s\n", prueba[0]);
	get_next_line(fd, prueba);
	printf("%s\n", prueba[0]);
	get_next_line(fd, prueba);
	printf("%s\n", prueba[0]);
	get_next_line(fd, prueba);
	printf("%s\n", prueba[0]);
	get_next_line(fd, prueba);
	printf("%s\n", prueba[0]);
	get_next_line(fd, prueba);
	printf("%s\n", prueba[0]);
	get_next_line(fd, prueba);
	printf("%s\n", prueba[0]);
	// SIN TEXTO QUE LEER
	get_next_line(fd, prueba);
	printf("%s\n", prueba[0]);
}