/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:50:02 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/10 00:20:51 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	ft_data_len(char ***arr)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

static t_3d_point	*ft_declare_new_point(int x, int y, int z)
{
	t_3d_point	*new_point;

	new_point = (t_3d_point *)malloc(sizeof(t_3d_point));
	new_point->x = x;
	new_point->y = y;
	new_point->z = z;
	return (new_point);
}

static t_3d_point	**ft_set_data(char ***arr)
{
	t_3d_point	**data;
	int			i;
	int			j;
	int			len;

	data = (t_3d_point **)malloc(sizeof(t_3d_point *) * (ft_data_len(arr) + 1));
	i = 0;
	j = 0;
	len = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			data[len++] = ft_declare_new_point(j, i, ft_atoi(arr[i][j]));
			j++;
		}
		i++;
	}
	data[len] = NULL;
	return (data);
}

static void	free_3d_array(char ***arr)
{
	int	i;
	int	j;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			free(arr[i][j++]);
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_3d_point	**ft_get_data(char *file)
{
	char		***arr;
	t_3d_point	**data;

	arr = ft_read_file(file);
	data = ft_set_data(arr);
	free_3d_array(arr);
	return (data);
}
