/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-la- <sade-la-@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:58:25 by sade-la-          #+#    #+#             */
/*   Updated: 2022/11/29 14:25:30 by sade-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_stash(int fd, char *stash)
{
	char	*buf;
	int		nr_bytes;

	if (!stash)
		stash = malloc(sizeof(char) * 1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nr_bytes = 1;
	while (!ft_strchr(buf, '\n') && nr_bytes != 0)
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[nr_bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash[0])
		return NULL;
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	line = ft_substr(stash, 0, i);
	if (stash[i] == '\n')
		line[i] = stash[i];
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = ft_get_stash(fd, stash);
	if (!stash)
		return NULL;
	line = ft_get_line(stash);
	// TO-DO
}

int	main(void)
{
	char *line = "";
	int fd = open("texto", O_RDONLY);
	while (line != NULL)
		line = get_next_line(fd);
		printf("%s", line);
	fd = close(fd);
	return(0);
}
