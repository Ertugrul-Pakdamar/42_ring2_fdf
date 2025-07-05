/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:12:43 by epakdama          #+#    #+#             */
/*   Updated: 2025/05/20 10:16:25 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		index1;
	int		index2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (res == NULL)
		return (NULL);
	index1 = -1;
	while (s1[++index1])
		res[index1] = s1[index1];
	index2 = -1;
	while (s2[++index2])
		res[index1++] = s2[index2];
	res[index1] = '\0';
	return (res);
}
