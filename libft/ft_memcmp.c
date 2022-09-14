/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:53:57 by jmarsh            #+#    #+#             */
/*   Updated: 2022/08/25 14:23:22 by jmarsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*strs1;
	const unsigned char	*strs2;

	i = 0;
	strs1 = (const unsigned char *)s1;
	strs2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (strs1[i] != strs2[i])
			return (strs1[i] - strs2[i]);
		i++;
	}
	return (0);
}
