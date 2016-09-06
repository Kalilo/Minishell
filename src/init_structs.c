/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 10:50:38 by khansman          #+#    #+#             */
/*   Updated: 2016/09/06 10:50:41 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_t_sub_var(t_sub_var *var)
{
	var->s1 = NULL;
	var->s2 = NULL;
	var->s3 = NULL;
	var->k = -1;
	var->l = 0;
	var->len = 0;
}

void	init_t_par(t_par *par)
{
	par->sing_quote = 0;
	par->dble_quote = 0;
	par->brac = 0;
	par->ang_brac = 0;
	par->sqr_brac = 0;
	par->str = NULL;
	par->k = 0;
}

void	init_t_env(t_env *env)
{
	env->pid = 0;
	/*
	**To be continued...
	*/
}
