/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:19:16 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/18 20:24:20 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_free_array(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
}

void	ft_free_3d_matrices(void ***arr)
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

int	ft_exit_prog(t_vars *vars)
{
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->map_2d)
		ft_free_array((void **)vars->map_2d);
	if (vars->map_3d)
		ft_free_array((void **)vars->map_3d);
	if (vars->map_size)
		free(vars->map_size);
	if (vars->file)
		free(vars->file);
	if (vars)
		free(vars);
	exit(0);
	return (0);
}

void	ft_map_not_found(t_vars *vars)
{
	ft_putstr_fd("Error: Map not found: ", 2);
	ft_putstr_fd(vars->file, 2);
	ft_putstr_fd("\n", 2);
	ft_exit_prog(vars);
}

void	ft_map_name_invalid(t_vars *vars)
{
	ft_putstr_fd("Error: Invalid map name. Please use a .fdf file.\n", 2);
	ft_exit_prog(vars);
}
