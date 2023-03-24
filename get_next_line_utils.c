/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-la- <sade-la-@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:58:28 by sade-la-          #+#    #+#             */
/*   Updated: 2022/11/29 14:14:38 by sade-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, len_s1);
	ft_memcpy(dst + len_s1, s2, len_s2);
	dst[len_s1 + len_s2] = '\0';
	free(s1);
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	else if ((char)c == '\0')
		return ((char *)s + i);
	else
		return NULL;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_p;
	const unsigned char	*src_p;
	size_t				i;

	dst_p = (char *)dst;
	src_p = (const char *)src;
	i = 0;
	if (!dst && !src)
		return NULL;
	while (i < n)
	{
		dst_p[i] = src_p[i];
		i++;
	}
	return (dst);
}
