/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 10:37:03 by khansman          #+#    #+#             */
/*   Updated: 2016/09/06 10:37:04 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



int	sub_var(t_env *env, char *str)
{
	t_sub_var	var;

	init_t_sub_var(&var);
	var.len = ft_strlen(str);
	var.s1 = ft_strnew(var.len);
	var.s2 = ft_strnew(var.len);
	var.s3 = ft_strnew(var.len);
	var.l = ft_unit_len(str, '$');
	ft_strncpy(var.s1, str, var.l);
	(str[var.l]) ? var.l++ : var.l;
	var.m = (var.l) ? ft_len_until(&str[var.l], ' ') : 0;
	ft_strncpy(var.s2, &str[var.l], var.m);
	ft_strncpy(var.s3, &str[var.l + var.m], var.len - var.m - var.l);
	
}

int	find_var(t_env *env, char *str)
{
	int			k;

	k = -1;
	while (str[++k])
		if (str[k] == '$')
			sub_var(env, str);
	return (k > 0);
}
