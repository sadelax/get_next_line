/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-la- <sade-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:58:23 by sade-la-          #+#    #+#             */
/*   Updated: 2023/07/16 04:52:51 by sade-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>		// printf (tester)
# include <unistd.h>	// write
# include <fcntl.h>		// read, open
# include <stdlib.h>	// malloc, free


# define BUFFER_SIZE 42

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(char *dst, char *src, size_t n);

#endif