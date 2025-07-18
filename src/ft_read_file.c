/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:17:45 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/18 20:05:19 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	ft_count_row(int fd)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		len++;
	}
	free(tmp);
	return (len);
}

char	***ft_read_file(char *file, t_vars *vars)
{
	char	***res;
	int		fd;
	int		len;
	int		i;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_map_not_found(file, vars), NULL);
	len = ft_count_row(fd);
	res = (char ***)malloc((len + 1) * sizeof(char **));
	close(fd);
	fd = open(file, O_RDONLY);
	i = 0;
	tmp = get_next_line(fd);
	while (i < len && tmp)
	{
		res[i] = ft_split(tmp, ' ');
		i++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	res[len] = NULL;
	close(fd);
	return (res);
}
