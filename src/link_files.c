#include "../includes/minishell.h"

void	link_files(t_env *env, char *line)
{
	t_data data;

	ft_bzero(&data, sizeof(t_data));
	data.env = E_EN;
	data.old_pwd = find_var_val(env, "OLDPWD");
	data.pwd = find_var_val(env, "PWD");
	data.path = find_var_val(env, "PATH");
	ft_lexer(line, &data);
}