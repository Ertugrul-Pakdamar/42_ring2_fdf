/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:05:47 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/07 07:05:47 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	ft_draw_pixel(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		sl;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, &sl, &endian);
	x = 400;
	y = 300;
	*(int *)(data + y * sl + x * (bpp / 8)) = color;
}
