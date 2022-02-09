/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:06:23 by llopes-n          #+#    #+#             */
/*   Updated: 2022/02/09 19:42:40 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_acheck_bk(int fd, char *buffer, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buffer);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract_format(char *line)
{
	size_t	count_nl;
	char	*backup;

	count_nl = 0;
	while (line[count_nl] != '\n' && line[count_nl] != '\0')
		count_nl++;
	if (line[count_nl] == '\0' || line[1] == '\0')
		return (NULL);
	backup = ft_substr(line, count_nl + 1, ft_strlen(line) - count_nl);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count_nl + 1] = '\0';
	return (backup);
}

char	*ft_get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup[OPEN_MAX + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_acheck_bk(fd, buffer, backup[fd]);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (line);
	backup[fd] = extract_format(line);
	return (line);
}
