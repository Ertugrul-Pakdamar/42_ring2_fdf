/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:23:34 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/18 12:47:06 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_BONUS_H
# define FT_FDF_BONUS_H

# include "ft_fdf.h"

int	ft_move_map(int key, t_vars *vars);
int	ft_rotate_map(int key, t_vars *vars);
int	ft_key_press(int key, t_vars *vars);
int	ft_key_release(int key, t_vars *vars);
int	ft_zoom_map(int key, t_vars *vars);
int	ft_reset(int key, t_vars *vars);

#endif