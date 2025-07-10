/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:19:16 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/10 19:46:51 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_free_array(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
}

void	ft_free_3d_matrices(void ***arr)
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
