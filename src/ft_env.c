#include "../includes/minishell.h"

void	ft_env(char **sa)
{
	int		i;

	i = 0;
	while (sa[i])
	{
		ft_putstr(sa[i++]);
		ft_putchar('\n');
	}
}

char	*find_var_val(t_env *env, const char *var)
{
	char	*seeked;
	int		k;

	k = 0;
	while (E_EN[k] != NULL)
	{
		if (ft_strstr(E_EN[k], var) != NULL)
		{
			seeked = ft_strchr(E_EN[k], '=');
			seeked++;
			chdir(seeked);
			return (seeked);
		}
		k++;
	}
	return (NULL);
}

void	update_env(t_env *env, char *var, char *new)
{
	char	*val;

	val = find_var_val(env, var);
}
