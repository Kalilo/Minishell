#include "../includes/minishell.h"

void	key_handler(t_env *env, char *key)
{
	if (*key == KEY_BKSP)
		I_L1[I_C1--] = '\0';
}
