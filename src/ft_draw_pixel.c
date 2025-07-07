/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:05:47 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/07 22:25:00 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_draw_pixel(void *img, t_2d_point *point, int color)
{
	char	*data;
	int		bpp;
	int		sl;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, &sl, &endian);
	*(int *)(data + point->y * sl + point->x * (bpp / 8)) = color;
}
