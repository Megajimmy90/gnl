/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-r <dnieto-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:56:33 by dnieto-r          #+#    #+#             */
/*   Updated: 2020/08/29 14:56:33 by dnieto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int 	get_next_line(int fd, char **line);
char 	*ft_strjoin(char *s1, char *s2);
void 	*ft_memcpy(void *dest, const void *src, size_t n);
char 	*ft_strdup(char *src);
int 	ft_strlen(const char *str);
char 	*ft_substr(char const *s, unsigned int start, size_t len);


#endif