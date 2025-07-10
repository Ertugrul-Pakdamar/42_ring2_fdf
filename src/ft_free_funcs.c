/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:19:16 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/10 19:24:15 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_free_3d_point_array(t_3d_point **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

void	ft_free_2d_point_array(t_2d_point **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

void	ft_free_array(char ***arr)
{
	int	i;
	int	j;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			free(arr[i][j++]);
		free(arr[i]);
		i++;
	}
	free(arr);
}
