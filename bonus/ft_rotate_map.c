/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:05:53 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/13 12:54:00 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf_bonus.h"

int	ft_rotate_map(int key, t_vars *vars)
{
	if (key == 65362)
		vars->a2--;
	else if (key == 65364)
		vars->a2++;
	else if (key == 65361)
		vars->a1--;
	else if (key == 65363)
		vars->a1++;
	else
		return (0);
	ft_free_array((void **)vars->map_2d);
	vars->map_2d = ft_3d_to_2d(vars->map_3d, vars);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (1);
}
