/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:07:24 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/01 14:53:13 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(const char *str, const char *to_find, size_t match_index)
{
	size_t	index;

	index = 0;
	while (to_find[index])
	{
		if (str[match_index + index] != to_find[index])
			return (0);
		index++;
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	index;
	size_t	size;

	if (str == NULL && len == 0)
		return (NULL);
	size = 0;
	while (to_find[size])
		size++;
	if (to_find[0] == '\0')
		return ((char *)str);
	index = 0;
	while (str[index] && index < len)
	{
		if (str[index] == to_find[0])
		{
			if (is_match(str, to_find, index) && index + size <= len)
				return (&((char *)str)[index]);
		}
		index++;
	}
	return (0);
}
