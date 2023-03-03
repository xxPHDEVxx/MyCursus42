/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:22:10 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/02/24 20:54:48 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Return the content of a file depending on the buffer'size
 * fd     = file descriptor of the file
 * buf    = container used to extract the file content
 * backup = static variable that will contain the content extracted
*/
static char	*get_content(int fd, char *buf, char *backup)
{
	int		read_size;
	char	*stock;

	read_size = 1;
	while (read_size != '\0')
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (0);
		else if (read_size == 0)
			break ;
		buf[read_size] = '\0';
		if (!backup)
			backup = ft_strdup("");
		stock = backup;
		backup = ft_strjoin(stock, buf);
		free(stock);
		stock = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

/*
 * extract the first part of the content that finished by a '\n'.
 * return the backup with the rest of the content.
 * line = part of the file's content that finished by a '\n'.
*/

static char	*line_extractor(char *line)
{
	char		*backup;
	size_t		count;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

/*
 * Return a line from a file 
 * fd = file descriptor of the file.
*/

char	*get_next_line(int fd)
{
	char			*line;
	char			*buf;
	static char		*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = get_content(fd, buf, backup);
	if (line == 0)
	{
		free (backup);
		backup = NULL;
	}
	free (buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = line_extractor(line);
	return (line);
}
