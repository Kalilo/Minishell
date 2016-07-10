/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 12:35:02 by ehansman          #+#    #+#             */
/*   Updated: 2016/07/10 14:23:01 by ehansman         ###   ########.fr       */
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
	update_env(env, "PWD", home);
}

char	*clip_path(char *path)
{
	int		i;
	int		j;
	char	*new_path;

	i = 0;
	j = 0;
	new_path = (char *)malloc(sizeof(char *) * ft_strlen(path));
	while (path[i] != '\0')
		i++;
	while (path[i] != '/')
		i--;
	while (j < i)
	{
		new_path[j] = path[j];
		j++;
	}
	return (new_path);
}

void	cd_one(t_env *env, char *dir)
{
	char	*path;

	path = find_var_val(env, "PWD=");
	update_env(env, "OLDPWD", path);
	if (ft_strcmp(dir, "..") == 0)
	{
		path = clip_path(path);
		if (chdir(path) == 0)
			update_env(env, "PWD", path);
		else
			ft_putstr(E_MESS12);
		free(path);
	}
	else if (scan_dir(dir, path) == 1)
	{
		path = add_path(path, dir);
		if (chdir(path) == 0)
			update_env(env, "PWD", path);
		else
			ft_putstr(E_MESS12);
		free(path);
	}
	else
		ft_putstr(E_MESS01);
}

void	ft_cd(t_env *env, char **sa)
{
	if (sa[1] == NULL)
		cd_home(env);
	else if (scan_slash(sa[1]) == 0 && sa[2] == NULL)
		cd_one(env, sa[1]);
	else
		ft_putstr(E_MESS02);
}
