/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:42:05 by epakdama          #+#    #+#             */
/*   Updated: 2025/05/20 10:15:19 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_count(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits = 1;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nb;
	int		index;

	nb = n;
	len = digits_count(nb);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	else if (nb == 0)
		res[0] = '0';
	index = len - 1;
	while (nb)
	{
		res[index--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
