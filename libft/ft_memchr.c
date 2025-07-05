/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:25:23 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/03 13:13:33 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;
	size_t	index;

	src = (char *)s;
	index = 0;
	while (index < n)
	{
		if (src[index] == (char)c)
			return (&src[index]);
		index++;
	}
	return (NULL);
}
