/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:50:31 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 00:09:15 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_format.h"
#include "libft.h"

int		ft_putstr_f(char const *s, t_format fmt)
{
	unsigned long	size;
	int				i;
	char	fill;

	fill = fmt->flags & FORMATF_ZERO ? '0' : ' ';
	i = 0;
	if (!s)
	{
		if (!fmt->output)
			return (write(1, "(NULL)", 7 > fmt->prec ? fmt->prec : 7));
		ft_strncpy(fmt->output, "(NULL)", 7 > fmt->prec ? fmt->prec : 7);
	}
	size = ft_strlen(s);
	if (fmt->prec > 0)
		size = ((long)size > fmt->prec) ? (unsigned long)fmt->prec : size;
	if ((long)size < fmt->width)
	{
		while ((long)size + i < fmt->width)
		{
			if (!fmt->output)
				write(fmt->fd, &fill, 1);
			else
				fmt->output[i] = fill;
		}
	}
	if (!fmt->output)
		return (i - 1 + write(fmt->fd, s, size));
	return (size + i - 1);
}
