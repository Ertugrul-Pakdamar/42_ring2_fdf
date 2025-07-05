/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:41:57 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/03 11:02:12 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*src;

	src = (char *)s;
	index = 0;
	while (src[index])
	{
		if (src[index] == (char)c)
			return (&src[index]);
		index++;
	}
	if ((char)c == '\0')
		return (&src[index]);
	return (NULL);
}
