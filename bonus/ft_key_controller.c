/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:16:08 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/13 00:22:03 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf_bonus.h"

int	ft_key_press(int key, t_vars *vars)
{
	vars->key = key;
	return (0);
}

int	ft_key_release(int key, t_vars *vars)
{
	(void)key;
	vars->key = 0;
	return (0);
}
