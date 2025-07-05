/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:34:33 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/04 08:04:46 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_len_calc(size_t *result, size_t index1, size_t size)
{
	if (size <= index1)
		*result += size;
	else
		*result += index1;
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	index1;
	size_t	index2;
	size_t	result;

	if (dest == NULL && size == 0)
		return (0);
	index1 = 0;
	index2 = 0;
	result = 0;
	while (dest[index1])
		index1++;
	while (src[result])
		result++;
	ft_len_calc(&result, index1, size);
	while (src[index2] && (index1 + 1) < size)
	{
		((char *)dest)[index1] = ((char *)src)[index2];
		index1++;
		index2++;
	}
	if (index1 != 0)
		((char *)dest)[index1] = '\0';
	return (result);
}
