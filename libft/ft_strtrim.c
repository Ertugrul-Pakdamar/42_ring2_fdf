/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:48:54 by epakdama          #+#    #+#             */
/*   Updated: 2025/05/20 10:17:04 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_find(char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		index;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && is_find(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && is_find(s1[end - 1], set))
		end--;
	res = (char *)malloc(end - start + 1);
	if (res == NULL)
		return (NULL);
	index = 0;
	while (start < end)
		res[index++] = s1[start++];
	res[index] = '\0';
	return (res);
}
