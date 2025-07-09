/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_point_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:30:24 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/10 00:20:35 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_2d_point	*ft_3d_point_calc(t_3d_point *point_3d, t_vars *vars)
{
	t_2d_point	*point_2d;
	double		iso_x;
	double		iso_y;
	int			a1;
	int			a2;

	a1 = 30;
	a2 = 30;
	point_2d = (t_2d_point *)malloc(sizeof(t_2d_point));
	if (!point_2d)
		return (NULL);
	iso_x = (point_3d->x * vars->spacing - point_3d->y * vars->spacing) * cos(a1
			* (PI / 180));
	iso_y = (point_3d->x * vars->spacing + point_3d->y * vars->spacing) * sin(a2
			* (PI / 180)) - point_3d->z * vars->spacing;
	point_2d->x = (int)(iso_x + vars->offset_x);
	point_2d->y = (int)(iso_y + vars->offset_y);
	return (point_2d);
}
