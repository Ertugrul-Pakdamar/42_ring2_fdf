/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:50:02 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/07 23:22:15 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	ft_count_row(int fd)
{
	int	len;

	len = 0;
	while (get_next_line(fd))
		len++;
	return (len);
}

char	***ft_get_data(char *file)
{
	char	***res;
	int		fd;
	int		len;
	int		i;
	char	*tmp;

	fd = open(file, O_RDONLY);
	len = ft_count_row(fd);
	res = (char ***)malloc(len * sizeof(char **));
	close(fd);
	fd = open(file, O_RDONLY);
	i = 0;
	tmp = get_next_line(fd);
	while (i < len && tmp)
	{
		res[i] = (char **)malloc(ft_strlen(tmp) * sizeof(char *));
		res[i] = ft_split(tmp, ' ');
		i++;
		tmp = get_next_line(fd);
	}
	close(fd);
	return (res);
}
