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

char	*ft_get_stash(int fd, char *stash){

	char	*buf;
	int readed;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!buf)
		return NULL;
	while (!(ft_strchr(buf, '\n')))
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if(readed == -1){
			free(buf);
			return NULL;
		}
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd){
	
	char *line;
	char *stash;
	
	if (fd < 0 && BUFFER_SIZE <= 0)
		return NULL;

	if(!stash){
		stash = ft_calloc(sizeof(char), BUFFER_SIZE);
	}
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
