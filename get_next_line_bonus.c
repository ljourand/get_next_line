/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:38:03 by ljourand          #+#    #+#             */
/*   Updated: 2021/11/22 11:23:43 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_last_line(char **str)
{
	char	*first_nl;
	char	*last_line;
	char	*buffer;

	if (ft_strlen(*str) == 0)
	{
		free(*str);
		return (0);
	}
	first_nl = ft_strchr(*str, '\n');
	last_line = ft_substr(*str, 0, first_nl - *str + 1);
	buffer = *str;
	*str = ft_substr(*str, first_nl - *str + 1, ft_strlen(*str));
	free(buffer);
	return (last_line);
}

char	*get_next_line(int fd)
{
	static char	*text[1024];
	char		*free_char;
	char		buffer[BUFFER_SIZE + 1];
	int			size;

	if (fd < 0)
		return (0);
	if (ft_strchr(text[fd], '\n'))
		return (ft_read_last_line(&text[fd]));
	size = read(fd, buffer, BUFFER_SIZE);
	while (size > 0)
	{
		buffer[size] = 0;
		free_char = text[fd];
		text[fd] = ft_strjoin(text[fd], buffer);
		if (free_char)
			free(free_char);
		if (ft_strchr(text[fd], '\n'))
			return (ft_read_last_line(&text[fd]));
		size = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_read_last_line(&text[fd]));
}
