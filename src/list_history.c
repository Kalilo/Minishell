/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 11:19:23 by jlangman          #+#    #+#             */
/*   Updated: 2016/09/10 10:55:25 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		clear_history(t_env *env)
{
	int		i;

	i = -1;
	while (I_HIS[++i])
	{
		if (I_HIS[i] != NULL)
		{
			free(I_HIS[i]);
			I_HIS[i] = NULL;
		}
	}
}

static void		search_history(char *str, t_env *env)
{
	int		i;

	i = -1;
	while (I_HIS[++i])
	{
		if (ft_strcmp(I_HIS[i], str) == 0)
		{
			ft_putnbr(i);
			ft_putstr("	");
			ft_putendl(I_HIS[i]);
		}
	}	
}

static void		sort_history(t_env *env, char **sa)
{
	if (ft_strcmp(sa[1], "-c") == 0)
		clear_history(env);
	else
	{
		ft_putstr("\n");
		search_history(sa[1], env);
	}
}

static void		print_history(t_env *env, int i, int j)
{
	ft_putnbr(j);
	ft_putstr("	");
	ft_putendl(I_HIS[i]);
}

/*void			store_history(t_env *env, int i, int j)
{

}*/

void			list_history(t_env *env, char **sa)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	if (sa[1] != NULL)
		sort_history(env, sa);
	else
	{
		ft_putstr("\n");
		while (I_HIS[i])
			i++;
		i--;
		if (i > 14)
		{
			j = i - 14;
			i = 14;
		}
		while (i >= 0)
		{
			store_history(env, i, j);
			print_history(env, i, j);
			i--;
			j++;
		}
	}
}
