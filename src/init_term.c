/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 12:48:33 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/05 13:05:01 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_init_deleg(char *str)
{
	ft_putstr_fd("ft_select: ", 2);
	if (str != NULL)
		ft_putendl_fd(str, 2);
	return (1);
}

int			init_term(void)
{
	int		k;
	int		result;
	char	*error;
	char	*type;

	k = 0;
	type = getenv("TERM");
	if (type == NULL && (k = 1))
		ft_init_deleg("Please specify terminal (setenv TERM).");
	if (k)
		result = 0;
	else
		result = tgetent(NULL, type);
	if (result < 0 && (k = 1))
		ft_init_deleg("failed to access the termcap database.");
	if (result == 0 && (k = ft_init_deleg(NULL)))
	{
		error = ft_strdup("undefined terminal type.\n");
		ft_putstr_fd(error, 2);
		free(error);
	}
	return (k);
}

int		ft_termsize(int y)
{
	int				ret;
	struct ttysize	twin;
	struct winsize	win;

	ret = 0;
	if (!ioctl(0, TIOCGSIZE, &twin))
		ret = (y) ? twin.ts_lines : twin.ts_cols;
	else if (!ioctl(0, TIOCGWINSZ, &win))
		ret = (y) ? win.ws_row : win.ws_col;
	else
	{
		ft_putstr("ioctl Error: Failed to determine window size.\n.");
		exit(0);
	}
	return (ret);
}

int		end_termios(t_env *all)
{
	write(1, "end_termios entered", 19);
	all->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(all->term)) == -1)
		return (0);
	tputs(tgetstr("te", NULL), 1, display);
	tputs(tgetstr("ve", NULL), 1, display);
	if (all->enter)
		ft_print_enter(all);
	return (1);
}

void	ft_print_enter(t_env *all)
{
	int	i;

	i = 0;
	while (all->ret[i])
	{
		ft_putstr(all->ret[i]);
		if (all->ret[i + 1])
			ft_putchar(32);
		i++;
	}
}

int		display(int c)
{
	return (write(2, &c, 1));
}
