/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:53:14 by jmarsh            #+#    #+#             */
/*   Updated: 2022/08/25 14:39:00 by jmarsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] == s1[i])
	{
		i++;
	}
	if (i < n)
	{
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	}
	return (0);
}
