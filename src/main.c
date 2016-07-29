/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:25:14 by khansman          #+#    #+#             */
/*   Updated: 2016/07/09 15:35:08 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**This function is not currently needed.
*/
void	*back_up_env(void *env)
{
	static void *e;

	if (!e && env)
		e = env;
	return ((void *)e);
}

int		main(void)
{
	t_env		env;
	char		*line;
	extern char	**environ;

	sigs();
	env.environ = get_env(environ);
	env.env_size = get_envsize(env.environ);
	line = NULL;
	back_up_env((void *)&env);
	while (1)
	{
		ft_putstr(SH_L);
		get_line(0, &line);
		if (check_line(line))
		{
			if (ft_memcmp(line, CM_EXIT, CM_EXIT_S) == 0)
				break ;
			if (ft_strchr_f(line, '=') != 0)
				set_env(&env, line);
			else
				com_sep(&env, line);
			if (line != NULL)
				free(line);
			line = NULL;
		}
	}
	exit(1);
}
