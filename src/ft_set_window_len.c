/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_window_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:04:00 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/09 01:18:26 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_set_window_len(t_3d_point **map, int *width, int *height)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i + 1] && map[i + 1]->x == 0)
			*width = map[i]->x * 15;
		i++;
	}
	*height = i * 15;
}
