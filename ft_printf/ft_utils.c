/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsh <jmarsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:15:56 by jmarsh            #+#    #+#             */
/*   Updated: 2022/09/13 11:55:26 by jmarsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *list, int *len)
{
	size_t	i;

	i = 0;
	if (!list)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (list[i] != '\0')
	{
		ft_putchar_len(list[i], len);
		i++;
	}
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_len('-', len);
		ft_putnbr(n * -1, len);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, len);
		ft_putchar_len(n % 10 + '0', len);
	}
}
