/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:05:51 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/08 22:57:39 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	free_3d_point_array(t_3d_point **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
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

int	main(void)
{
	t_vars	*vars;
	int		i;

	// Create
	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 600, "MiniLibX Test");
	vars->img = mlx_new_image(vars->mlx, 800, 600);
	// Draw
	vars->map = ft_get_data("test_maps/42.fdf");
	i = 0;
	while (vars->map[i] != NULL)
		printf("%d\n", vars->map[i++]->x);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	// Listen Key
	mlx_key_hook(vars->win, handle_key, vars);
	mlx_loop(vars->mlx);
	return (0);
}
