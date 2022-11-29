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

char	*get_next_line(int fd)
{
	char *buf;
	char *line_in_buffer;
	int file;

	buf = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buf)
		return NULL;
	file = 1;
	while (!ft_strchr(buf, '\n') && file != 0)
	{
		file = read(fd, buf, BUFFER_SIZE);
		if (file == -1)
		{
			free(buf);
			return NULL;
		}
		buf[file] = '\0';
		line_in_buffer = ft_strjoin(line_in_buffer, buf);
	}
	free(buf);
	return(line_in_buffer);
}

int	main(void)
{
	char *line;
	
	int fd = open ("mi_fichero", O_RDONLY);
	line = "";
	while (line != NULL)
		line = get_next_line(fd);
		printf("%s", line);
	fd = close(fd);
	return(0);
}
