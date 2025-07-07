/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_point_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:30:24 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/07 22:55:33 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_2d_point	*ft_3d_point_calc(t_3d_point *point)
{
	t_2d_point	*res;

	res = (t_2d_point *)malloc(sizeof(t_2d_point));
	res->x = (point->x - point->y) * cos(point->x);
	res->y = (point->x + point->y) * sin(point->x) + point->z;
	return (res);
}
