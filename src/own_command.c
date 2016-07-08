#include "../includes/minishell.h"

int is_own(char *s)
{
	return (0);
}

void	own_command(char **sa)
{
	if (ft_memcmp(sa[0], "echo", 5) == 0)
		ft_echo(sa);
	else if (ft_memcmp(sa[0], "cd", 3) == 0)
		ft_cd(sa);
	else if (ft_memcmp(sa[0], "setenv", 7) == 0)
		ft_export(sa);
	else if (ft_memcmp(sa[0], "unsetenv", 9) == 0)
		ft_unset(sa);
	else if (ft_memcmp(sa[0], "env", 4) == 0)
		ft_env(sa);
	else
		ft_putstr(E_MESS05);
}
