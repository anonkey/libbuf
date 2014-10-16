/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 20:29:24 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 03:18:50 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_format.h"
#include "libft.h"

int			ft_putnbr_f(long long nbr, t_format fmt)
{
	char	*nbstr;
	char	fill;
	char	sign;

	fill = fmt->flags & FORMATF_ZERO ? '0' : ' ';
	if (fmt->flags & FORMATF_BLANK)
		sign = ' ';
	else
		sign = fmt->flags & FORMATF_SIGN ? '+' : '\0';
	nbstr = ft_getnbr_len(nbr, sign, fmt->width, fill);
	if (!fmt->output)
		return (write(fmt->fd, nbstr, ft_strlen(nbstr)));
	return (ft_strlen(ft_strcpy(fmt->output, nbstr)));
}

int			ft_putssize_f(long long nbr, t_format fmt)
{
	char	*nbstr;
	char	sign;
	int		len;

	if (fmt->flags & FORMATF_BLANK)
		sign = ' ';
	else
		sign = fmt->flags & FORMATF_SIGN ? '+' : '\0';
	nbstr = ft_getnbr_len(nbr, sign, 0, '\0');
	len = ft_strlen(nbstr);
	while (len++ < fmt->prec)
		*--nbstr = '0';
	while (len++ <= fmt->width)
		*--nbstr = ' ';
	if (!fmt->output)
		return (write(fmt->fd, nbstr, ft_strlen(nbstr)));
	return (ft_strlen(ft_strcpy(fmt->output, nbstr)));
}
