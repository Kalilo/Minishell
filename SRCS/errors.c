#include "minishell.h"

int	error1(t_data *data)
{
	if (data->error == 1)
		ft_putstr("Error: No such file or directory.\n");
	//else if ()
}

int	error(t_data *data)
{
	if (0 <= t_data->error && t_data->error <= 9)
		return (error1(data));
}