#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (true);
	if (c == '\r' || c == '\f' || c == '\v')
		return (true);
    return (false);
}