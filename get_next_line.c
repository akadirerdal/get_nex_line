/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:31:13 by aberdal           #+#    #+#             */
/*   Updated: 2026/02/28 17:59:54 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **repo)
{
	char	*newline;
	char	*line;
	char	*remain;
	size_t	len;

	if (!*repo)
		return (NULL);
	newline = ft_strchr(*repo, '\n');
	if (newline)
		len = newline - *repo + 1;
	else
		len = ft_strlen(*repo);
	line = ft_substr(*repo, 0, len);
	if (!line)
		return (NULL);
	if ((*repo)[len] != '\0')
		remain = ft_substr(*repo, len, ft_strlen(*repo + len));
	else
		remain = NULL;
	free(*repo);
	*repo = remain;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*repo;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		read_bytes;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(repo, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
            break;
		buffer[read_bytes] = '\0';
		tmp = ft_strjoin(repo, buffer);
		free(repo);
		repo = tmp;
	}
	if (repo && *repo)
		return (extract_line(&repo));
	free(repo);
	repo = NULL;
	return (NULL);
}