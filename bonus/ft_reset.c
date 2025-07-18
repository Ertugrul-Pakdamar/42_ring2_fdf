/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:41:21 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/18 12:52:08 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_reset(int key, t_vars *vars)
{
	if (key == 'r' || key == 'R')
	{
		ft_free_array((void **)vars->map_2d);
		ft_free_array((void **)vars->map_3d);
		free(vars->map_size);
		ft_get_map(vars->file, vars);
	}
	else
		return (1);
	vars->map_2d = ft_3d_to_2d(vars->map_3d, vars);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
