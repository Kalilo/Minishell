#include "../includes/minishell.h"

int is_own(char *s)
{
	if (ft_memcmp(s, "env", 3) == 0)
		return (1);
	if (ft_memcmp(s, "cd", 2) == 0)
		return (1);
	if (ft_memcmp(s, "setenv", 6) == 0)
		return (1);
	if (ft_memcmp(s, "unsetenv", 8) == 0)
		return (1);
	if (ft_memcmp(s, "echo", 4) == 0)
		return (1);
	return (0);
}

void	own_command(t_env *env, char **sa, char *s)
{
	if (ft_memcmp(sa[0], "echo", 4) == 0)
		ft_echo(sa);
	else if (ft_memcmp(sa[0], "cd", 2) == 0)
		ft_cd(env, sa);
	else if (ft_memcmp(sa[0], "setenv", 6) == 0)
		ft_export(sa, E_SI, s);
	else if (ft_memcmp(sa[0], "unsetenv", 8) == 0)
		ft_unset(&sa, s);
	else if (ft_memcmp(sa[0], "env", 3) == 0)
		ft_env(E_EN);
	else
		ft_putstr(E_MESS05);
}
