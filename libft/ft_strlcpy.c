/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:29:33 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/04 08:04:31 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	len;
	char	*s;
	char	*d;

	d = (char *)dest;
	s = (char *)src;
	len = 0;
	while (s[len])
		len++;
	if (size == 0)
		return (len);
	index = 0;
	while (index < size - 1 && s[index])
	{
		d[index] = s[index];
		index++;
	}
	d[index] = '\0';
	return (len);
}
