/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/27 15:31:41 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/03 14:30:19 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_dynstr.h"









int		main(void)
{
	t_dynstr	dstr;
	int			i;
	char		*tmp;

	dstr = ft_dynstrnew(64);
	i = 0;
	while (i < 1000000)
	{
	    ft_putnbr(dstr->size);
	    ft_putchar('\n');
		tmp = ft_itoa(rand());
		ft_dynstradd(dstr, tmp);
		ft_dynstradd(dstr, "||--||");
		free(tmp);
		++i;
	}
	ft_putendl("END");
	ft_dynstrput(dstr);
	tmp = ft_dynstrflush(dstr);
	ft_putendl(tmp);
	ft_strdel(&tmp);
	ft_dynstrdel(&dstr);
	return (0);
}