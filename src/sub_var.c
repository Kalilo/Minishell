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



char	*sub_var(t_env *env, char *str)
{
	t_sub_var	var;

	var.len = ft_strlen(str);
	var.s1 = ft_strnew(var.len);
	var.s2 = ft_strnew(var.len);
	var.s3 = ft_strnew(var.len);
	var.l = ft_len_until(str, '$');
	ft_strncpy(var.s1, str, var.l);
	(str[var.l]) ? var.l++ : var.l;
	var.m = (var.l) ? ft_len_until(&str[var.l], ' ') : 0;
	ft_strncpy(var.s2, &str[var.l], var.m);
	ft_strncpy(var.s3, &str[var.l + var.m], var.len - var.m - var.l);

	printf("s1 = '%s'\n", var.s1);
	printf("s2 = '%s'\n", var.s2);
	printf("s3 = '%s'\n", var.s3);

	var.value = ft_strdup(find_var_val(env, var.s2));
	printf("value = '%s'\n", var.value);

	var.p1 = ft_strjoin(var.s1, var.value);
	printf("p1 = '%s'\n", var.p1);
	var.result = ft_strjoin(var.p1, var.s3);
	printf("result = '%s'\n", var.result);

	return (var.result);
}

int		scan_for_var(t_env *env, char **str)
{
	int			k;

	k = -1;
	while (*str[++k])
		if (*str[k] == '$')
			*str = sub_var(env, *str);
	return (k > 0);
}
