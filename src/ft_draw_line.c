/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:48:02 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/12 23:50:37 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_draw_loop(t_2d_point tmp_point_0, t_2d_point *point_1,
		t_vars *vars, t_line_vars *line_var)
{
	while (1)
	{
		if (tmp_point_0.x == point_1->x && tmp_point_0.y == point_1->y)
			break ;
		ft_draw_pixel(vars, &tmp_point_0);
		line_var->e2 = 2 * line_var->err;
		if (line_var->e2 > -line_var->dy)
		{
			line_var->err -= line_var->dy;
			tmp_point_0.x += line_var->sx;
		}
		if (line_var->e2 < line_var->dx)
		{
			line_var->err += line_var->dx;
			tmp_point_0.y += line_var->sy;
		}
	}
}

void	ft_draw_line(t_vars *vars, t_2d_point *point_0, t_2d_point *point_1)
{
	t_line_vars	*line_var;
	t_2d_point	tmp_point_0;

	line_var = (t_line_vars *)malloc(sizeof(t_line_vars));
	tmp_point_0 = *point_0;
	line_var->dx = abs(point_1->x - tmp_point_0.x);
	line_var->dy = abs(point_1->y - tmp_point_0.y);
	if (tmp_point_0.x < point_1->x)
		line_var->sx = 1;
	else
		line_var->sx = -1;
	if (tmp_point_0.y < point_1->y)
		line_var->sy = 1;
	else
		line_var->sy = -1;
	line_var->err = line_var->dx - line_var->dy;
	ft_draw_loop(tmp_point_0, point_1, vars, line_var);
	free(line_var);
}
