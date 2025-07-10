/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_window_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:11:30 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/10 17:55:03 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_init_bounds(t_bounds *bounds)
{
	bounds->min_x = 1000000;
	bounds->min_y = 1000000;
	bounds->max_x = -1000000;
	bounds->max_y = -1000000;
}

static void	ft_update_bounds(t_bounds *bounds, t_2d_point *point)
{
	if (point->x < bounds->min_x)
		bounds->min_x = point->x;
	if (point->x > bounds->max_x)
		bounds->max_x = point->x;
	if (point->y < bounds->min_y)
		bounds->min_y = point->y;
	if (point->y > bounds->max_y)
		bounds->max_y = point->y;
}

static void	ft_get_map_bounds(t_vars *vars, t_bounds *bounds, int *width,
		int *height)
{
	int			i;
	t_2d_point	*point;

	i = 0;
	ft_init_bounds(bounds);
	while (vars->map[i])
	{
		point = ft_3d_point_calc(vars->map[i], vars);
		ft_update_bounds(bounds, point);
		free(point);
		i++;
	}
	*width = bounds->max_x - bounds->min_x;
	*height = bounds->max_y - bounds->min_y;
}

void	ft_set_window_len(t_vars *vars, int *width, int *height)
{
	t_bounds	bounds;
	int			map_w;
	int			map_h;
	int			margin_x;
	int			margin_y;

	vars->spacing = DEFAULT_SPACING;
	ft_get_map_bounds(vars, &bounds, &map_w, &map_h);
	while ((map_w + vars->spacing * 4 > MAX_WIDTH || map_h + vars->spacing
			* 2 > MAX_HEIGHT) && vars->spacing > MIN_SPACING)
	{
		vars->spacing--;
		ft_get_map_bounds(vars, &bounds, &map_w, &map_h);
	}
	margin_x = vars->spacing * 4;
	margin_y = vars->spacing * 2;
	*width = map_w + margin_x * 2;
	*height = map_h + margin_y * 2;
	if (*width > MAX_WIDTH)
		*width = MAX_WIDTH;
	if (*height > MAX_HEIGHT)
		*height = MAX_HEIGHT;
	vars->offset_x = (*width - map_w) / 2 - bounds.min_x;
	vars->offset_y = (*height - map_h) / 2 - bounds.min_y;
}
