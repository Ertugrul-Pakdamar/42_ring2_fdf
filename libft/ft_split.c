/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:42:16 by epakdama          #+#    #+#             */
/*   Updated: 2025/06/03 14:20:55 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	leak_check(char ***res, int *res_i)
{
	if (!(*res)[(*res_i)++])
	{
		while ((*res_i)-- > 0)
			free((*res)[*res_i]);
		free((*res));
		return (1);
	}
	return (0);
}

static int	check_and_alloc(char ***res, char c, char const *s)
{
	if (!s)
		return (0);
	(*res) = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!(*res))
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		s_index;
	int		res_index;
	int		start;

	if (!check_and_alloc(&result, c, s))
		return (NULL);
	s_index = 0;
	res_index = 0;
	while (s[s_index])
	{
		while (s[s_index] && s[s_index] == c)
			s_index++;
		start = s_index;
		while (s[s_index] && s[s_index] != c)
			s_index++;
		if (start < s_index)
		{
			result[res_index] = ft_substr(s, start, s_index - start);
			if (leak_check(&result, &res_index))
				return (NULL);
		}
	}
	result[res_index] = NULL;
	return (result);
}
