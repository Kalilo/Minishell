/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:18:14 by khansman          #+#    #+#             */
/*   Updated: 2016/07/10 14:19:33 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		do_command(t_env *env, char *com)
{
	char	*str;
	char	**arr;
	pid_t	forked;

	str = NULL;
	arr = NULL;
	forked = fork();
	if (forked == 0)
	{
		arr = ft_strsplit(com, ' ');
		execve(com, arr, E_EN);
		str = find_path(env, arr[0]);
		if (str == NULL)
			ft_putstr(E_MESS02);
		else
			execve(str, arr, E_EN);
		exit(0);
	}
	else
		wait(0);
	return (1);
}

void	command(t_env *env, char *s)
{
	char	**sa;

	if (s == NULL)
		return ;
	sa = NULL;
	rm_tabs(&s);
	sa = ft_strsplit(s, ' ');
	if (arg_valid(sa, count(s, ' ')))
	{
		if (is_own(sa[0]))
			own_command(env, sa, s);
		else
			do_command(env, s);
	}
	else
		error(1);
	free2d(sa);
}
