/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:19:16 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 11:27:25 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free2d(char **arr)
{
	int		k;

	k = 0;
	while (arr[k] != NULL)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
}

void	exit_prog(t_env *env)
{
	if (E_EN != NULL)
		free2d(E_EN);
	if (I_HIS != NULL)
		free2d(I_HIS);
	if (I_L1)
		free(I_L1);
	if (I_L2)
		free(I_L2);
	if (env->l)
		free(env->l);
	if (I_CUR)
		free(I_CUR);
	ft_bzero(env, sizeof(t_env));
	exit(1);
}
