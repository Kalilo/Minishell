#include "../includes/minishell.h"

int			find_string_pos(char **arr, char *str)
{
	int		k;

	k = -1;
	if (!arr || !arr[k])
		return (-2);
	while (arr[++k])
		if (!ft_strcmp(arr[k], str))
			return (k);
	return (-1);
}

static void com_hist_add(t_env *env, char *str)
{
	int		k;
	char	*s;

	s = (str == NULL) ? ft_strjoin(I_L1, I_L2) : ft_strdup(str);
	k = -1;
	while (I_HIS[++k] && k < MAX_HIST)
		if (!ft_strcmp(I_HIS[k], s))
		{
			free(s);
			return ;
		}
	if (k == MAX_HIST)
		free(I_HIS[--k]);
	while (k > 0)
	{
		I_HIS[k] = I_HIS[k - 1];
		k--;
	}
	I_HIS[k] = s;
}

static void com_hist_next(t_env *env)
{
	int		k;
	char	*str;

	str = ft_strjoin(I_L1, I_L2);
	k = find_string_pos(I_HIS, str) + 1;
	if (!k || !I_HIS[k])
		return ;
	com_hist_add(env, str);
	free(I_L1);
	free(I_L2);
	I_L1 = I_HIS[k];
	I_L2 = NULL;
}

static void com_hist_prev(t_env *env)
{
	int		k;
	char	*str;

	str = ft_strjoin(I_L1, I_L2);
	k = find_string_pos(I_HIS, str) - 1;
	if (!k + 1 || !I_HIS[k])
		return ;
	com_hist_add(env, str);
	free(I_L1);
	free(I_L2);
	I_L1 = I_HIS[k];
	I_L2 = NULL;
}

int			com_history(t_env *env, int action)
{
	if (action == HIST_STORE)
		com_hist_add(env, NULL);
	else if (action == HIST_NEXT)
		com_hist_next(env);
	else if (action == HIST_PREV)
		com_hist_prev(env);
	else
		return (0);
	return (1);
}
