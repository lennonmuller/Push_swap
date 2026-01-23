#include "../../includes/push_swap.h"

static int	ft_has_only_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

static void	safe_strjoin(char **tmp, const char *s2)
{
	char	*res;
	char	*old;

	old = *tmp;
	res = ft_strjoin(old, s2);
	if (!res)
	{
		free(old);
		ft_error();
		exit(1);
	}
	*tmp = res;
	free(old);
}

static char	*ft_join_args(char **av)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup("");
	if (!tmp)
	{
		ft_error();
		exit(1);
	}
	i = 1;
	while(av[i])
	{
		if (ft_has_only_spaces(av[i]))
		{
			ft_error();
			free(tmp);
			exit(1);
		}
		safe_strjoin(&tmp, av[i]);
		safe_strjoin(&tmp, " ");
		i++;
	}
	return (tmp);
}

char    **ft_parsing_stack(char **av)
{
    char    **str;
    char    *s;

    s = NULL;
    s = ft_join_args(av);
	str = ft_split(s, ' ');
	free(s);
	return (str);
}