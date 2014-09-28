#include <unistd.h>
#include "libft.h"

//TODO: width specifier, fill char
static int		ft_printradix(long double nb, int prec, char *buf)
{
	char	digit;
	int	size;

	size = prec + 1;
	*buf++ = RADIX_CHAR;
	while (prec > 0)
	{
		if (nb != 0)
		{
			nb *= 10;
			digit = (char)nb;
			nb -= (long double)digit;
			*buf++ = digit + '0';
		}
		else
			*buf++ = '0';
		--prec;
	}
	return (size);
}

int			ft_putldouble(long double nb, int prec, int sign)
{
	char	buf[MAX_DBLSIZE];
	int	size;
	long double	mask;
	char	digit;

	size = 0;
	mask = 1.0;
	if (nb < 0 || sign)
	{
		buf[size++] = nb < 0 ? '-' : '+';
		if (nb < 0)
		    nb = 0 - nb;
	}
	while (nb / mask > 10.0)
		mask *= 10.0;
	while (mask >= 1.0)
	{
		nb -= mask * (long double)(digit = (char)(nb / mask));
		mask /= 10.0;
		buf[size++] = digit + '0';
	}
	if (prec > 0)
		size += ft_printradix(nb, prec, buf + size);
	buf[size] = '\0';
	return (write(1, buf, size), ft_putchar('\n'));
}
