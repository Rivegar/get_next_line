/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivero- <arivero-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:12:10 by arivero-          #+#    #+#             */
/*   Updated: 2023/05/15 09:52:15 by arivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(char *stash, int fd, char *buff)
{
	ssize_t		rline;

	rline = 1;
	while (rline && !ft_strchr(stash, '\n'))
	{
		rline = read(fd, buff, BUFFER_SIZE);
		if (rline == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[rline] = 0;
		stash = ft_strjoin_free(stash, buff);
	}
	free(buff);
	return (stash);
}

static char	*point_next_line(char **stash)
{
	char	*line;
	char	*ptr;

	ptr = *stash;
	while (*ptr && *ptr != '\n')
		ptr++;
	if (*ptr == '\n')
		ptr++;
	line = ft_substr(*stash, 0, (size_t)(ptr - *stash));
	if (!line)
	{
		free(*stash);
		return (NULL);
	}
	ptr = ft_substr(ptr, 0, ft_strlen(ptr));
	free(*stash);
	*stash = ptr;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	buff = malloc(sizeof(*buff) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		free(stash);
		return (NULL);
	}
	stash = read_line(stash, fd, buff);
	if (!stash)
		return (NULL);
	if (!*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (point_next_line(&stash));
}
