/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:19:16 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/12 23:30:56 by epakdama         ###   ########.fr       */
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
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_free_array((void **)vars->map_2d);
	ft_free_array((void **)vars->map_3d);
	free(vars->map_size);
	free(vars);
	exit(0);
	return (0);
}
