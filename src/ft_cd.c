/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 12:01:12 by ehansman          #+#    #+#             */
/*   Updated: 2016/09/09 11:42:34 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd_prev(t_env *env)
{
	char	*prev;
	char	*temp;

	prev = find_var_val(env, "OLDPWD");
	temp = ft_strdup(find_var_val(env, "PWD"));
	chdir(prev);
	update_env(env, "PWD", prev);
	update_env(env, "OLDPWD", temp);
	free(temp);
}

int		check(char **sa)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (sa[1][i] != '\0')
	{
		if (sa[1][i] == '/')
			count++;
		i++;
	}
	return (count);
}

void	ft_cd(t_env *env, char **sa)
{
	int		i;
	int		count;
	char	**args;

	i = 0;
	if (sa[1] == NULL)
	{
		cd_home(env);
		return ;
	}
	else if (!ft_strcmp(sa[1], "-"))
	{
		cd_prev(env);
		return ;
	}
	count = check(sa);
	args = ft_strsplit(sa[1], '/');
	i = 0;
	while (count > 0)
	{
		if (args[i] == NULL)
			return ;
		env = ft_cd_sub(env, args[i], count);
		count--;
		i++;
	}
}
