/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 01:16:42 by vmistry           #+#    #+#             */
/*   Updated: 2026/01/07 13:05:16 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
		while (len--)
			*d++ = *s++;
	return (dst);
}

static char	*extract_line(char *buffer, char *line)
{
	char	*nl;
	char	*res;
	char	*remainder;

	nl = ft_strchr(buffer, '\n');
	remainder = ft_substr(buffer, 0, (nl - buffer) + 1);
	res = ft_strjoin(line, remainder);
	free(line);
	free(remainder);
	ft_memmove(buffer, nl + 1, ft_strlen(nl + 1) + 1);
	return (res);
}

int	handle_buffer(char *buffer, char **line)
{
	char		*tmp;

	if (ft_strchr(buffer, '\n'))
		return (1);
	if (buffer[0] == '\0')
		return (0);
	tmp = *line;
	*line = ft_strjoin(tmp, buffer);
	free(tmp);
	buffer[0] = '\0';
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_BUFFER][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		rd;

	if (fd < 0 || fd >= MAX_BUFFER || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	rd = 1;
	while (rd > 0)
	{
		if (handle_buffer(buffer[fd], &line))
			return (extract_line(buffer[fd], line));
		rd = read(fd, buffer[fd], BUFFER_SIZE);
		if (rd < 0)
			return (free(line), NULL);
		buffer[fd][rd] = '\0';
	}
	return (line);
}
