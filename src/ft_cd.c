/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:20:22 by khansman          #+#    #+#             */
/*   Updated: 2016/07/09 15:20:48 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		scan_slash(char *str)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (str[k] != '\0')
	{
		if (str[k] == '\\')
			l++;
		k++;
	}
	return (l);
}

void	cd_home(t_env *env)
{
	char	*home;

	home = find_var_val(env, "HOME=");
	chdir(home);
}

void	cd_one(t_env *env, char *dir)
{
	char	*path;

	path = NULL;
	path = find_var_val(env, "PWD=");
	if (ft_strcmp(dir, "..") == 0)
	{
	}
	else if (scan_dir(dir, path))
	{
		path = add_path(path, dir);
		chdir(path);
		update_env(env, "PWD", path);
		free(path);
	}
}

void	ft_cd(t_env *env, char **sa)
{
	if (ft_strcmp(sa[1], "..") != 0)
		update_env(env, "OLDPWD", find_var_val(env, "PWD="));
	if (sa[1] == NULL)
		cd_home(env);
	else
	{
		if (scan_slash(sa[1]) == 0 && sa[2] == NULL)
			cd_one(env, sa[1]);
	}
}
