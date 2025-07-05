/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:52 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/04 08:05:29 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned int	index;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	index = 0;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d < s)
	{
		while (index < n)
		{
			d[index] = s[index];
			index++;
		}
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (d);
}
