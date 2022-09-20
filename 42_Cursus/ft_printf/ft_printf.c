/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsh <jmarsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:12:40 by jmarsh            #+#    #+#             */
/*   Updated: 2022/09/13 11:55:16 by jmarsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check(char in, va_list *list, int *len, int *i)
{
	if (in == 's')
		ft_putstr(va_arg(*list, char *), len);
	else if (in == 'd' || in == 'i')
		ft_putnbr(va_arg(*list, int), len);
	else if (in == 'u')
		ft_u(va_arg(*list, unsigned int), len);
	else if (in == 'x')
		ft_xx(va_arg(*list, unsigned int), len, 'x');
	else if (in == 'X')
		ft_xx(va_arg(*list, unsigned int), len, 'X');
	else if (in == 'p')
		ft_p(va_arg(*list, size_t), len);
	else if (in == 'c')
		ft_putchar_len(va_arg(*list, int), len);
	else if (in == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *in, ...)
{
	va_list	list;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(list, in);
	while (in[i] != '\0')
	{
		if (in[i] == '%')
		{
			i++;
			ft_check(in[i], &list, &len, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)in[i], &len);
			i++;
		}
	}
	va_end(list);
	return (len);
}
