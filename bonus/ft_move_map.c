/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:02:24 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/18 09:36:55 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf_bonus.h"

static void	ft_move_up(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map_3d[i])
	{
		vars->map_3d[i]->y -= 1;
		vars->map_3d[i]->x -= 1;
		i++;
	}
	ft_free_array((void **)vars->map_2d);
	vars->map_2d = ft_3d_to_2d(vars->map_3d, vars);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
}

static void	ft_move_down(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map_3d[i])
	{
		vars->map_3d[i]->y += 1;
		vars->map_3d[i]->x += 1;
		i++;
	}
	ft_free_array((void **)vars->map_2d);
	vars->map_2d = ft_3d_to_2d(vars->map_3d, vars);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
}

static void	ft_move_left(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map_3d[i])
	{
		vars->map_3d[i]->x -= 1;
		vars->map_3d[i]->y += 1;
		i++;
	}
	ft_free_array((void **)vars->map_2d);
	vars->map_2d = ft_3d_to_2d(vars->map_3d, vars);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
}

static void	ft_move_right(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map_3d[i])
	{
		vars->map_3d[i]->x += 1;
		vars->map_3d[i]->y -= 1;
		i++;
	}
	ft_free_array((void **)vars->map_2d);
	vars->map_2d = ft_3d_to_2d(vars->map_3d, vars);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
}

int	ft_move_map(int key, t_vars *vars)
{
	if (key == 'd' || key == 'D')
		ft_move_right(vars);
	else if (key == 'a' || key == 'A')
		ft_move_left(vars);
	else if (key == 's' || key == 'S')
		ft_move_down(vars);
	else if (key == 'w' || key == 'W')
		ft_move_up(vars);
	else
		return (0);
	return (1);
}
