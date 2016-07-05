#include "minishell.h"

int	error1(int err)
{
	if (err == 1)
		ft_putstr(E_MESS01);
	else if (err == 2)
		ft_putstr(E_MESS02);
	else i f(err == 3)
		ft_putstr(E_MESS03);
	else
		return (0);
	return (1);
}

int	error(int err)
{
	if (0 <= err && err <= 9)
		return (error1(err));
	return (1);
}