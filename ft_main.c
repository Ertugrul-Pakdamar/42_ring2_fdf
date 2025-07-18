/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:05:51 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/18 12:45:48 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	ft_render_next_frame(t_vars *vars)
{
	int	i;
	int	apsis_len;

	mlx_clear_window(vars->mlx, vars->win);
	apsis_len = vars->map_size->apsis_len;
	i = 0;
	while (vars->map_2d[i + apsis_len])
	{
		vars->color_z = abs(vars->map_3d[i]->z) * 42 - 62000;
		if (vars->map_2d[i + 1] && (i + 1) % apsis_len >= 1)
			ft_draw_line(vars, vars->map_2d[i], vars->map_2d[i + 1]);
		if (vars->map_2d[i + apsis_len])
			ft_draw_line(vars, vars->map_2d[i], vars->map_2d[i + apsis_len]);
		i++;
	}
	while (vars->map_2d[i + 1])
	{
		vars->color_z = abs(vars->map_3d[i]->z) * 42 - 62000;
		if (vars->map_2d[i + 1] && (i + 1) % apsis_len >= 1)
			ft_draw_line(vars, vars->map_2d[i], vars->map_2d[i + 1]);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

static int	ft_key_handler(int key, t_vars *vars)
{
	if (key == 65307)
		ft_exit_prog(vars);
	return (0);
}

static void	ft_init_window(t_vars *vars, char *file)
{
	int	width;
	int	height;

	ft_get_map(file, vars);
	ft_set_window_len(vars, &width, &height);
	vars->map_2d = ft_3d_to_2d(vars->map_3d, vars);
	vars->width = width;
	vars->height = height;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, width, height, "MiniLibX Test");
	vars->img = mlx_new_image(vars->mlx, width, height);
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	if (argc != 2)
		return (1);
	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	vars->file = ft_strdup(argv[1]);
	ft_init_window(vars, vars->file);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, DestroyNotify, KeyPressMask, ft_exit_prog, vars);
	mlx_key_hook(vars->win, ft_key_handler, vars);
	mlx_loop_hook(vars->mlx, ft_render_next_frame, vars);
	mlx_loop(vars->mlx);
	return (0);
}
