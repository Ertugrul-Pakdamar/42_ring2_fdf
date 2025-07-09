/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:05:51 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/10 00:21:13 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <stdio.h>

static void	free_3d_point_array(t_3d_point **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

static int	render_next_frame(t_vars *vars)
{
	int			i;
	t_2d_point	*point;

	mlx_clear_window(vars->mlx, vars->win);
	i = 0;
	while (vars->map[i] != NULL)
	{
		point = ft_3d_point_calc(vars->map[i], vars);
		//printf("i:%d --- x:%d --- y:%d\n", i, point->x, point->y);
		ft_draw_pixel(vars, point, 0x00FF00);
		free(point);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

static int	handle_key(int key, t_vars *vars)
{
	if (key == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free_3d_point_array(vars->map);
		free(vars);
		exit(0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;
	int		width;
	int		height;

	if (argc != 2)
		return (1);
	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	vars->map = ft_get_data(argv[1]);
	ft_set_window_len(vars, &width, &height);
	vars->width = width;
	vars->height = height;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, width, height, "MiniLibX Test");
	vars->img = mlx_new_image(vars->mlx, width, height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_key_hook(vars->win, handle_key, vars);
	mlx_loop(vars->mlx);
	return (0);
}
