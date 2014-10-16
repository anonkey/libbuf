#ifndef T_FORMAT_H
# define T_FORMAT_H

# define PRINTF_FLAGS "#0- +"
# define FORMATF_NONE 0
# define FORMATF_ALT 1
# define FORMATF_ZERO 2
# define FORMATF_LEFT 4
# define FORMATF_BLANK 8
# define FORMATF_SIGN 16

typedef struct		s_format
{
	char			*output;
	int				fd;
	char			flags;
	int				width;
	int				prec;
	int				len;
	char			type;
}					t_format_s;

typedef t_format_s	*t_format;

#endif
