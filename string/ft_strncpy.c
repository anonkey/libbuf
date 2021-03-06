/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/17 04:24:40 by tseguier          #+#    #+#             */
/*   Updated: 2014/07/02 16:01:10 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (NULL);
	while (n > 0)
	{
		--n;
		*(s1 + n) = *(s2 + n);
	}
	return (s1);
}
