/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:15:01 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/26 19:33:04 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_newline(int fd, char *stat_s)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stat_s, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stat_s);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stat_s = ft_strjoin(stat_s, buffer);
	}
	free(buffer);
	return (stat_s);
}

static char	*get_res(char *stat_s)
{
	char	*res;
	int		i;

	i = 0;
	if (!stat_s[0])
		return (NULL);
	while (stat_s[i] && stat_s[i] != '\n')
		i++;
	res = (char *)malloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (stat_s[i] && stat_s[i] != '\n')
	{
		res[i] = stat_s[i];
		i++;
	}
	if (stat_s[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

static char	*set_stat(char *stat_s)
{
	char	*new_stat;
	int		i;
	int		j;

	i = 0;
	while (stat_s[i] && stat_s[i] != '\n')
		i++;
	if (!stat_s[i])
	{
		free(stat_s);
		return (NULL);
	}
	new_stat = (char *)malloc(ft_strlen(&stat_s[i + 1]) + 1);
	if (!new_stat)
		return (NULL);
	j = 0;
	i++;
	while (stat_s[i])
		new_stat[j++] = stat_s[i++];
	new_stat[j] = '\0';
	free(stat_s);
	return (new_stat);
}

char	*get_next_line(int fd)
{
	static char	*stat_s[1024];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat_s[fd] = read_newline(fd, stat_s[fd]);
	if (!stat_s[fd])
		return (NULL);
	res = get_res(stat_s[fd]);
	stat_s[fd] = set_stat(stat_s[fd]);
	return (res);
}
