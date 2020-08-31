/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-r <dnieto-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:55:59 by dnieto-r          #+#    #+#             */
/*   Updated: 2020/08/29 14:55:59 by dnieto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int ft_strlen(const char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

char *ft_strdup(char *src)
{
	int s;
	char *dest;
	int i;

	i = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	dest = (char *)malloc(sizeof(*dest) * (s + 1));
	while (i < s)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}


char *ft_strjoin(char *s1, char *s2)
{
	int len1;
	int len2;
	char *res;
	int i;
	int j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return ((!s1) ? ft_strdup(s2) : ft_strdup(s1));
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if (!(res = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = 0;
	if (!n || dest == src)
		return (dest);
	
	while (n--)
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return (dest);
}


char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ptr;
	size_t i;
	int j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (int)start)
		return (ft_strdup(""));
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] != '\0' && i < (len + start))
	{
		ptr[j] = s[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}