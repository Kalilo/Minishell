/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_cb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 08:58:28 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 08:58:31 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	copy_line(t_env *env)
{
	if (I_L1 == NULL && I_L2 == NULL)
		return ;
	if (I_CB != NULL)
		free(I_CB);
	if (I_L1 == NULL && I_L2 != NULL)
		I_CB = ft_strdup(I_L2);
	else if (I_L1 != NULL && I_L2 == NULL)
		I_CB = ft_strdup(I_L1);
	else if (I_L1 != NULL && I_L2 != NULL)
		I_CB = ft_strjoin(I_L1, I_L2);
}

void	copy_l2(t_env *env)
{
	if (I_L2 == NULL)
		return ;
	if (I_CB != NULL)
		free(I_CB);
	I_CB = ft_strdup(I_L2);
}

/*
**	Needed:
**	(line 47) remalloc
*/

void	paste_l1(t_env *env)
{
	if (I_CB == NULL)
		return ;
	ft_memcpy(&I_L1[I_C1 + 1], I_CB, ft_strlen(I_CB));
	I_C1 = ft_strlen(I_L1) - 1;
}
