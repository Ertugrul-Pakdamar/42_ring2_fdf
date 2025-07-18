/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 06:42:02 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/18 20:12:40 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "get_next_line_bonus.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <mlx_int.h>

# define DEFAULT_SPACING 50
# define MIN_SPACING 1
# define MAX_WIDTH 1280
# define MAX_HEIGHT 720
# define PI 3.14159265358979323846

typedef struct s_2d_point
{
	int				x;
	int				y;
}					t_2d_point;

typedef struct s_3d_point
{
	int				x;
	int				y;
	int				z;
}					t_3d_point;

typedef struct s_2d_map_size
{
	int				size;
	int				apsis_len;
	int				ordinate_len;
}					t_2d_map_size;

typedef struct s_line_vars
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_line_vars;

typedef struct s_bounds
{
	int				min_x;
	int				min_y;
	int				max_x;
	int				max_y;
}					t_bounds;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	t_2d_point		**map_2d;
	t_3d_point		**map_3d;
	int				spacing;
	int				offset_x;
	int				offset_y;
	int				width;
	int				height;
	t_2d_map_size	*map_size;
	int				color_z;
	int				a1;
	int				a2;
	int				key;
	t_bounds		*bounds;
	char			*file;
}					t_vars;

t_2d_point			*ft_3d_point_calc(t_3d_point *point_3d, t_vars *vars);
t_2d_point			**ft_3d_to_2d(t_3d_point **data_3d, t_vars *vars);
char				***ft_read_file(char *file, t_vars *vars);
void				ft_draw_pixel(t_vars *vars, t_2d_point *point);
void				ft_get_map(char *file, t_vars *vars);
void				ft_set_window_len(t_vars *vars, int *width, int *height);
void				ft_get_map_len(char ***arr, t_vars *vars);
void				ft_free_3d_matrices(void ***arr);
void				ft_free_array(void **arr);
void				ft_draw_line(t_vars *vars, t_2d_point *point_0,
						t_2d_point *point_1);
int					ft_exit_prog(t_vars *vars);
void				ft_map_not_found(char *file, t_vars *vars);

#endif
