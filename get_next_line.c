/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivero- <arivero-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:12:10 by arivero-          #+#    #+#             */
/*   Updated: 2023/04/21 09:50:34 by arivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char **temp)
{
	char	*line;
	char	*ptr;

	ptr = *temp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr (*temp, 0, (size_t)(ptr - *temp));
	if (!line)
	{
		free (*temp);
		return (NULL);
	}
	ptr = ft_substr (ptr, 0, ft_strlen (ptr));
	free (*temp);
	*temp = ptr;
	return (line);
}

static char	*read_line(char *temp, int fd, char *buf)
{
	ssize_t		r;

	r = 1;
	while (r && !ft_strchr(temp, '\n'))
	{
		r = read (fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free (buf);
			free (temp);
			return (NULL);
		}
		buf[r] = 0;
		temp = ft_strjoin_free(temp, buf);
	}
	free (buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[4096];
	char		*buf;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp[fd])
		temp[fd] = ft_strdup("");
	if (!temp[fd])
		return (NULL);
	buf = malloc (sizeof (*buf) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free (temp[fd]);
		return (NULL);
	}
	temp[fd] = read_line (temp[fd], fd, buf);
	if (!temp[fd])
		return (NULL);
	if (!*temp[fd])
	{
		free (temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	return (next_line(&temp[fd]));
}
