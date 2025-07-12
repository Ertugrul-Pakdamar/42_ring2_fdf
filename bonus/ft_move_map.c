/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:02:24 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/13 00:41:56 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf_bonus.h"

static void	ft_move_up(t_vars *vars)
{
	int	i;

	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	i = 0;
	while (vars->map_2d[i])
	{
		vars->map_2d[i]->y -= 2;
		i++;
	}
}

static void	ft_move_down(t_vars *vars)
{
	int	i;

	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	i = 0;
	while (vars->map_2d[i])
	{
		vars->map_2d[i]->y += 2;
		i++;
	}
}

static void	ft_move_left(t_vars *vars)
{
	int	i;

	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	i = 0;
	while (vars->map_2d[i])
	{
		vars->map_2d[i]->x -= 2;
		i++;
	}
}

static void	ft_move_right(t_vars *vars)
{
	int	i;

	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	i = 0;
	while (vars->map_2d[i])
	{
		vars->map_2d[i]->x += 2;
		i++;
	}
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
