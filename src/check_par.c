/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_par.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 08:55:39 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 08:55:41 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	init_par(t_par *par, t_env *env)
{
	P_SI = 0;
	P_DB = 0;
	P_B = 0;
	P_AB = 0;
	P_SB = 0;
	P_B_SL = 0;
	if (I_L1 != NULL && I_L2 != NULL)
		P_STR = ft_strjoin(I_L1, I_L2);
	else
		P_STR = (I_L1 != NULL) ? ft_strdup(I_L1) : ft_strdup(I_L2);
	P_K = -1;
}

static void	par_condition(t_par *par)
{
	if (P_SK == '(')
		P_B++;
	else if (P_SK == ')')
		P_B--;
	else if (P_SK == '{')
		P_AB++;
	else if (P_SK == '}')
		P_AB--;
	else if (P_SK == '[')
		P_SB++;
	else if (P_SK == ']')
		P_SB--;
	else if (P_SK == '\'')
		P_SI++;
	else if (P_SK == '"')
		P_DB++;
	else if ((P_SK == '\\') && (P_STR[P_K + 1] == '\n') 
			&& ((P_STR[P_K + 2] == '\0') || (P_STR[P_K + 2] == '\r')))
		P_B_SL++;
}

static int	par_valid(t_par *par)
{
	if (P_B != 0)
		return (0);
	if (P_AB != 0)
		return (0);
	if (P_SB != 0)
		return (0);
	if (P_SI != 0 && P_SI % 2 != 0)
		return (0);
	if (P_DB != 0 && P_DB % 2 != 0)
		return (0);
	if (P_B_SL)
		return (0);
	if (P_B_SL)
		return (0);
	return (1);
}

static int	check_back_slash(t_env *env, t_par *par)
{
/*	char	*pos;

	pos = ft_strchr(P_STR, '\\');
	printf("cpoint 1\n");//debug
	if (pos != NULL)
	{
		put_bin((unsigned char *)pos);
		printf("c1-1 pos = '%s'\n", pos);//debug
		while (++pos)
		{
			printf("letter = '%c'\n", *pos);//debug
			if (ft_isalnum(*pos) && *pos != '\\')
				return (0);
		}
		printf("cpoint 2\n");//debug
		return (1);
	}
	printf("cpoint 3\n");//debug
	return (0);*/
	int		k;

	//k = ft_len_until(par->str, 92);
	printf("k = '%i', str = '%s'\n", k, par->str);
/*	if (k > 0)
	{
		while (P_STR[k++])
			if (ft_isalnum(P_STR[k]))
				return (0);
		return (1);
	}*/
	return (0);
}

int			check_par(t_env *env)
{
	t_par	par;
	char	result;
	char	*tmp;

	if (I_L1 == NULL && I_L2 == NULL)
		return (-1);
	init_par(&par, env);/*
//	printf("str = '%s'\n", par.str);//debug
	if ((tmp = ft_strchr(par.str, '\\')) != NULL)
	{
		printf("Backslash found, tmp = '%s\n", tmp);//debug
		//put_bin((unsigned char *)tmp);
		while (++*tmp)
			if (ft_isalnum(*tmp))
				goto x2;
		printf("Backslash valid\n");//debug
		free(par.str);
		result = (0);
	}
	else
	{
		x2:
		printf("Normal execution\n");//debug
		//put_bin((unsigned char *)tmp);*/
		while (par.str[++(par.k)])
			par_condition(&par);
		free(par.str);
		result = (par_valid(&par));
//	}
	I_TMP2 = (result) ? 0 : 1;
	return (result);
}
