#include "../includes/minishell.h"

int is_own(char *s)
{
	if (ft_memcmp(s, "env", 4) == 0)
		return (1);
	if (ft_memcmp(s, "cd", 3) == 0)
		return (1);
	if (ft_memcmp(s, "setenv", 7) == 0)
		return (1);
	if (ft_memcmp(s, "unsetenv", 9) == 0)
		return (1);
	if (ft_memcmp(s, "echo", 5) == 0)
		return (1);
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
