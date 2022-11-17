/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:30:18 by araji-af          #+#    #+#             */
/*   Updated: 2022/11/07 19:30:18 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_free(int fd, char *holder)
{
	char	*tmp;
	int		bytes;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	buffer[0] = 0;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			return (free(buffer), holder);
		if (bytes < 0)
			return (free(buffer), NULL);
		buffer[bytes] = 0;
		tmp = holder;
		holder = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	return (free(buffer), holder);
}

size_t	strlen_new_line(char *buffer)
{
	size_t	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*updatable[OPEN_MAX];
	char		*free_this_one;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	updatable[fd] = join_free(fd, updatable[fd]);
	if (!updatable[fd])
		return (NULL);
	if (!*updatable[fd])
	{
		free(updatable[fd]);
		updatable[fd] = NULL;
		return (NULL);
	}
	free_this_one = updatable[fd];
	line = ft_substr(free_this_one, 0, strlen_new_line(free_this_one) + 1);
	updatable[fd] = ft_substr(free_this_one, strlen_new_line(line) + 1,
			ft_strlen(free_this_one + strlen_new_line(free_this_one) + 1));
	free(free_this_one);
	return (line);
}
