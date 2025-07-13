/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_point_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:30:24 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/13 12:39:17 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_2d_point	*ft_3d_point_calc(t_3d_point *point_3d, t_vars *vars)
{
	t_2d_point	*point_2d;
	double		iso_x;
	double		iso_y;

	if (!vars->a1 || !vars->a2)
	{
		vars->a1 = 1830;
		vars->a2 = 1830;
	}
	if (vars->a1 < 0)
		vars->a1 = -vars->a1;
	if (vars->a2 < 0)
		vars->a2 = -vars->a2;
	point_2d = (t_2d_point *)malloc(sizeof(t_2d_point));
	if (!point_2d)
		return (NULL);
	iso_x = (point_3d->x * vars->spacing - point_3d->y * vars->spacing)
		* cos(vars->a1 * (PI / 180));
	iso_y = (point_3d->x * vars->spacing + point_3d->y * vars->spacing)
		* sin(vars->a2 * (PI / 180)) - point_3d->z * (vars->spacing / 5);
	point_2d->x = (int)(iso_x + vars->offset_x);
	point_2d->y = (int)(iso_y + vars->offset_y);
	return (point_2d);
}
