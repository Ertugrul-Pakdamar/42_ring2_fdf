/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:05:51 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/08 11:23:31 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	handle_key(int key, void *param)
{
	(void)param;
	if (key == 65307)
		exit(0);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	***data;

	data = ft_get_data("test_maps/42.fdf");
	printf("%s\n", data[10][18]);
	return (0);
}
*/

int	main(void)
{
	void		*mlx;
	void		*win;
	void		*img;
	t_2d_point	*point;

	// Create
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "MiniLibX Test");
	img = mlx_new_image(mlx, 800, 600);
	// Draw
	point = (t_2d_point *)malloc(sizeof(t_2d_point));
	point->x = 400;
	point->y = 300;
	ft_draw_pixel(img, point, 0x00FF00);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	// Listen Key
	mlx_key_hook(win, handle_key, NULL);
	mlx_loop(mlx);
	// Exit
	mlx_destroy_image(mlx, img);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
