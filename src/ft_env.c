/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:22:04 by khansman          #+#    #+#             */
/*   Updated: 2016/07/09 15:22:23 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	call_env(t_env env, char *s)
{
	int		k;
	char	**sa;
	
	k = 1;
	if (ft_strchr(s, ' ') == NULL)
	{
		ft_env(env.environ);
		return ;
	}
	sa = ft_strsplit(s, ' ');
	while (sa[k] != NULL)
	{
		//ft_setenv(&env, &sa[k]);
		k++;
	}
	free2d(sa);
	ft_env(env.environ);
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

void	update_env(t_env *env, char *var, char *n)
{
	char	*val;
	char	*temp;
	int		k;

	k = 0;
	while (E_EN[k] != NULL)
	{
		if (ft_strncmp(E_EN[k], var, ft_strlen(var)) == 0)
		{
			free(&E_EN[k]);
			temp = ft_strjoin(var, "=");
			E_EN[k] = ft_strjoin(temp, n);
			free(temp);
		}
		k++;
	}
}
