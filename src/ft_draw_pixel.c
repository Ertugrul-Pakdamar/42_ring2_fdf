/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:05:47 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/09 23:53:30 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_draw_pixel(t_vars *vars, t_2d_point *point, int color)
{
	char	*data;
	int		bpp;
	int		sl;
	int		endian;

	if (point->x < 0 || point->y < 0 || point->x >= vars->width
		|| point->y >= vars->height)
		return ;
	data = mlx_get_data_addr(vars->img, &bpp, &sl, &endian);
	*(int *)(data + point->y * sl + point->x * (bpp / 8)) = color;
}
