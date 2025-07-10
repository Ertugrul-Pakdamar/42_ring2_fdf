/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:21:35 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/10 18:33:00 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_get_map_len(char ***arr, t_vars *vars)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	vars->map_size = (t_2d_map_size *)malloc(sizeof(t_2d_map_size));
	vars->map_size->size = len;
	vars->map_size->apsis_len = j;
	vars->map_size->ordinate_len = i;
}
