/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 08:58:22 by khansman          #+#    #+#             */
/*   Updated: 2016/09/11 11:37:24 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	Had a few difficalties getting the right keys for some values,
**		thus some of the key actions will have to be assigned to keys of our
**		selection. So far the most promising are the unused F keys.
**
**	Old code:
**		else if (CTRL_C == *key) ft_ctrl_c(env);
**		else if (CTRL_Z == *key) ft_ctrl_z(env);
*/

static void	replace_l1(t_env *env, char *replacement)
{
	if (I_L1 != NULL)
		free(I_L1);
	I_L1 = ft_strdup(replacement);
	I_C1 = ft_strlen(replacement) - 1;
}

static void	key_tab(t_env *env)
{
	if (!ft_strcmp(I_L1, "ec") || !ft_strcmp(I_L1, "e"))
		replace_l1(env, "echo ");
	else if (!ft_strcmp(I_L1, "em") || !ft_strcmp(I_L1, "ema"))
		replace_l1(env, "emacs ");
	else if (!ft_strcmp(I_L1, "ex"))
		replace_l1(env, "exit");
	else if (!ft_strcmp(I_L1, "se") || !ft_strcmp(I_L1, "s"))
		replace_l1(env, "setenv ");
	else if (!ft_strcmp(I_L1, "u") || !ft_strcmp(I_L1, "un"))
		replace_l1(env, "unsetenv ");
	else if (!ft_strcmp(I_L1, "h") || !ft_strcmp(I_L1, "his"))
		replace_l1(env, "history ");
	else if (!ft_strcmp(I_L1, "c"))
		replace_l1(env, "cd ");
	else if (!ft_strcmp(I_L1, "en"))
		replace_l1(env, "env ");
	else if (!ft_strcmp(I_L1, "he") || !ft_strcmp(I_L1, "hel"))
		replace_l1(env, "help");
	else if (!ft_strcmp(I_L1, "v") || !ft_strcmp(I_L1, "vi"))
		replace_l1(env, "vim ");
}

static void	key_handler2(t_env *env, char *key)
{
	if (!ft_strcmp(K_F19, key))
		paste_l1(env);
	else if (!ft_strcmp(K_F18, key))
		copy_line(env);
	else if (!ft_strcmp(K_F17, key))
		copy_l2(env);
	else if (!ft_strcmp(K_TAB, key) || *key == 9)
		key_tab(env);
}

/*
**	Debug Lines (start)
**		put_bin((unsigned char *)key);//debug
**		printf("Key Pressed: '%s'\n", key);//debug
*/

void		key_handler(t_env *env, char *key)
{
	if (*key == K_BKSP && I_C1 >= 0)
	{
		I_L1[I_C1--] = '\0';
		ft_putstr("\b \b");
	}
	else if (!ft_strcmp(K_UP, key))
		com_history(env, HIST_PREV);
	else if (!ft_strcmp(K_DOWN, key))
		com_history(env, HIST_NEXT);
	else if (!ft_strcmp(K_RIGHT, key))
		ke_right(env);
	else if (!ft_strcmp(K_LEFT, key))
		ke_left(env);
	else if (!(ft_strcmp(K_DEL, key)))
		ke_del(env);
	else if (!ft_strcmp(K_F5, key))
		ke_jump_left(env);
	else if (!ft_strcmp(K_F6, key))
		ke_jump_right(env);
	else if (!ft_strcmp(K_F13, key) || !ft_strcmp(K_HOME, key))
		ke_home(env);
	else if (!ft_strcmp(K_F14, key) || !ft_strcmp(K_END, key))
		ke_end(env);
	else
		key_handler2(env, key);
}
