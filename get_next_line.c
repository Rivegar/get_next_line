/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivero- <arivero-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:12:10 by arivero-          #+#    #+#             */
/*   Updated: 2023/04/14 15:57:01 by arivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>


char	*get_next_line(int fd)
{
	char	*line;
	static char	auxbuf;
	ssize_t	n;
	int		i;
	i = 0;
	n = 0;
	auxbuf = 0;
	line = (char *)malloc(BUFF_SIZE);
	if(!line)
		return (NULL);
	while (i < BUFF_SIZE - 1)
	{
		n = read(fd, &auxbuf, BUFF_SIZE);
		if (n == -1)
		{
			free(line);
			return (NULL);
		}
		else if (n == 0)
		{
			break ;
		}
		else
		{
			line[i++] = auxbuf;
			if (auxbuf == '\n')
				break ;
		}
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
