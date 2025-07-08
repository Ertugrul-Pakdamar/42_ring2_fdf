/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 06:42:02 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/08 23:01:03 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct s_2d_point
{
	int			x;
	int			y;
}				t_2d_point;

typedef struct s_3d_point
{
	int			x;
	int			y;
	int			z;
}				t_3d_point;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	t_3d_point	**map;
}				t_vars;

void			ft_draw_pixel(void *img, t_2d_point *point, int color);
t_2d_point		*ft_3d_point_calc(t_3d_point *point);
char			***ft_read_file(char *file);
t_3d_point		**ft_get_data(char *file);

#endif
