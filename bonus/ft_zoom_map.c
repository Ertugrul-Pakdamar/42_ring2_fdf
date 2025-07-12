/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:41:06 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/13 01:01:13 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf_bonus.h"

int	ft_zoom_map(int key, t_vars *vars)
{
	if (key == 'u' || key == 'U')
		vars->spacing += 2;
	else if (key == 'y' || key == 'Y')
		vars->spacing -= 2;
	else
		return (0);
	vars->map_2d = ft_3d_to_2d(vars->map_3d, vars);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (1);
}
