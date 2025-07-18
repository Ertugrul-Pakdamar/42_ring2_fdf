/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:50:02 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/10 18:34:28 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static t_3d_point	*ft_declare_new_point(int x, int y, int z)
{
	t_3d_point	*new_point;

	new_point = (t_3d_point *)malloc(sizeof(t_3d_point));
	if (!new_point)
		return (NULL);
	new_point->x = x;
	new_point->y = y;
	new_point->z = z;
	return (new_point);
}

static t_3d_point	**ft_set_data(char ***arr, t_vars *vars)
{
	t_3d_point	**data;
	int			i;
	int			j;
	int			len;

	data = (t_3d_point **)malloc(sizeof(t_3d_point *) * (vars->map_size->size
				+ 1));
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

t_2d_point	**ft_3d_to_2d(t_3d_point **data_3d, t_vars *vars)
{
	int			i;
	t_2d_point	**data;

	data = (t_2d_point **)malloc(sizeof(t_2d_point *) * (vars->map_size->size
				+ 1));
	i = 0;
	while (data_3d[i])
	{
		data[i] = ft_3d_point_calc(data_3d[i], vars);
		i++;
	}
	data[i] = NULL;
	return (data);
}

void	ft_get_map(t_vars *vars)
{
	char	***arr;

	if (ft_strncmp(&vars->file[ft_strlen(vars->file) - 4], ".fdf", 4))
		ft_map_name_invalid(vars);
	arr = ft_read_file(vars);
	if (!arr)
		ft_map_not_found(vars);
	ft_get_map_len(arr, vars);
	vars->map_3d = ft_set_data(arr, vars);
	ft_free_3d_matrices((void ***)arr);
}
